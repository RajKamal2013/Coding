#include "read.h"

/*
 * TO DO:
 * 1. Use fcntl advisory lock to make it more concurrent 
 * 2. Use pread instead of read to make sure, we dont play with file offset 
 * 3. Add better logging facility.
 * 4. Changes for Non Blocking read calls.
 * 5. Add inotify things 
 * 6. Reduce the system calls.
 */

/* Check the validity of file descritor*/
int check_fd_validity(int fd)
{
	return ((fcntl(fd, F_GETFD) != -1) || (errno != EBADF));
}

/* Initialize the cookies */
read_cookie* read_cookie_init(int fd, size_t total_bytes, size_t read_quanta)
{
	read_cookie *rc = NULL;
	/* check the validity of the fd <see more about fcntl() */
	if (!check_fd_validity(fd)) {
		fprintf(stderr, "ERR: API :%s, Invalid FD\n", __func__);
		exit(EXIT_FAILURE);
	}
	rc = malloc(sizeof(read_cookie));
	if (rc != NULL) {
		rc = memset(rc, '\0', sizeof(read_cookie));
		rc = (read_cookie *)rc;
	} else {
		printf("Error malloc Failed \n");
	}

	rc->rc_fd = fd;
	rc->rc_bytes_read = 0;
	rc->rc_quanta = read_quanta;
	rc->rc_total_bytes = total_bytes;
	rc->rc_end_pos = lseek(rc->rc_fd, 0, SEEK_END);
	rc->rc_cur_pos = lseek(rc->rc_fd, 0, SEEK_SET); /* setting to start offset */
	rc->rc_error = 0;
	return rc;
}


/* Reads the first data. Caller needs to free the memory of char */
char *read_cookie_first(read_cookie *rc)
{
	char *buff = malloc(sizeof(rc->rc_quanta));
	int len = 0;
	rc->rc_cur_pos = 0;
	off_t pos;
	/* set current pos to SEEK_SET*/
	pos = lseek(rc->rc_fd, 0, SEEK_SET);
	/* Other way would be to use pread, if I dont want to affect file pos */
	if (buff != NULL) {
		len = read_one_buffer(rc->rc_fd, buff, rc->rc_quanta, rc->rc_cur_pos);
		rc->rc_bytes_read += len;
		pos = lseek(rc->rc_fd, 0, SEEK_CUR);
		rc->rc_cur_pos = pos;
//		printf("\n DBG: API:%s : Data Read %s and Data len : %d , Data offset : % lld \n", __func__, buff, len, pos);
	} else {
		rc->rc_error = CHAR_NOT_ALLOCATED;
		fprintf(stderr, "ERR: API :%s, Read Buffer Not Allocated \n", __func__);
		printf(" API: %s :I am getting Buffer Null \n", __func__);
		//ASSERT(0);
		exit(EXIT_FAILURE);
		return NULL;
	}

	if (len == 0) {
		free(buff);
		rc->rc_cur_pos = rc->rc_end_pos;
		buff = NULL;
	}
	return buff;
}

/* It read the next data as part of loop. Caller needs to free the memory of char */
char *read_cookie_next(read_cookie *rc, char *buff)
{
	off_t pos;
	/* need to confirm if we can do this */
	if (buff == NULL) {
		buff = malloc(sizeof(rc->rc_quanta));
		if (buff == NULL) {
			fprintf(stderr, "ERR: API:%s Failed to alloc memory\n",
				__func__);
			//assert(0);
			exit(EXIT_FAILURE);
			return NULL;
		} else {
			buff = (char *)buff;
		}
	} else {
		memset(buff, '\0', sizeof(rc->rc_quanta));
	}
	int len = 0;
	/* get position of the current file */
	pos = lseek(rc->rc_fd, 0, SEEK_CUR);
	if (pos != rc->rc_cur_pos) {
		printf("Warning :File offset is not set to %lld, instead set to %lld \n", rc->rc_cur_pos, pos);
		lseek(rc->rc_fd, SEEK_SET, rc->rc_cur_pos);
	}
	/* Other way would be to use pread, if I dont want to affect file pos */
	if (buff != NULL) {
		len = read_one_buffer(rc->rc_fd, buff, rc->rc_quanta, rc->rc_cur_pos);
		rc->rc_bytes_read += len;
		pos = lseek(rc->rc_fd, 0, SEEK_CUR);
		rc->rc_cur_pos = pos;
//		printf("\nDBG: API :%s : Data Read %s and Data len : %d , Data offset : % lld \n", __func__, buff, len, pos);
	} else {
		rc->rc_error = CHAR_NOT_ALLOCATED;
		fprintf(stderr, "ERR: API :%s, Read Buffer Not Allocated \n", __func__);
		printf(" API: %s :I am getting Buffer Null \n", __func__);
		//ASSERT(0);
		exit(EXIT_FAILURE);
		return NULL;
	}
	if (len == 0) {
		//free(buff);
		rc->rc_cur_pos = rc->rc_end_pos;
		//buff = NULL;
	}
	return buff;
}

/* Meat of every read call */
int read_one_buffer(int fd, char *buffer, ssize_t bytes_to_read, off_t pos)
{
	int len = bytes_to_read;
	int ret = 0;
	char *temp = buffer; 
	/* check the validity of the fd <see more about fcntl() */
	if (!check_fd_validity(fd)) {
		fprintf(stderr,"ERR: API %s, Invalid FD", __func__ );
		exit(EXIT_FAILURE);
		return -1;
	}
	/*
	 * case handles
	 * 1. When we are non block and we return 0 and not reading complete data 
	 * 2. When we are interrupted before or while reading data
	 * 3. When we reach EOF, normal case 
	 * 4. Partial Reads <Due to interrupt, being non blocking>
	 */

//	printf("DBG : API : %s, Reading %zd data from offset :%llu \n", __func__, bytes_to_read, pos); 
	(void) memset(buffer, '\0', len);
	while(len != 0 && ((ret = read(fd, buffer, len))!= 0)) {
		if (ret == -1) {
			if (errno ==  EINTR) {
				/* Retry after 10 seconds */
				sleep(10);  /* can be better way to do it */
			} else if (errno == EAGAIN) {
				/* Retry after 10 seconds. non blocking call */
				sleep(10);
			} else {
				fprintf(stderr,"ERR: API %s, Read Not Possible, "
					"%s Error NO:%d\n", __func__,
					strerror(errno), errno);
				//ASSERT(0);
				exit(EXIT_FAILURE);
			}
		//	printf("DBG:API %s We have reading issue \n", __func__);
		} else if(ret == 0) {  /* Either EOF or Call Blocked and returned due to error */
			printf("\n DBG: API: %s Date completely Read : Data -> %s + Read : %d + Req : %d \n", __func__, buffer, ret, len);
			buffer = temp;
			ret = 0;
		} else {
			len = len - ret;
			if (len != 0) {
				temp  = buffer;
	//			printf("\n DBG: API: %s Date Partially Read : Data -> %s , Read : %d  Req : %d \n", __func__, buffer, ret, len);
				buffer = buffer + ret;
			}
		}
	}
//	if (ret == 0) {
//		printf("\nDBG : API : %s, Temp : %s and Data : %s \n", __func__, temp, buffer);
//	}
	buffer = temp;
//	if (ret == 0) {
//		printf("\nDBG : API : %s, Temp : %s and Data : %s \n", __func__, temp, buffer);
//	}
	pos = lseek(fd, 0, SEEK_CUR);
//	printf("DBG : API : %s, Read Data : %s --> Size %zd offset :%llu \n", __func__, buffer, bytes_to_read, pos); 
	return ret;
}

/* We need to free the cookie now */ 
int read_cookie_free(read_cookie *rc)
{
	rc->rc_fd = -1;
	free(rc);
	rc = NULL;
	return 0;
}
