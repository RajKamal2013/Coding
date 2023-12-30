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
int check_read_fd_validity(int fd)
{
	return ((fcntl(fd, F_GETFD) != -1) || (errno != EBADF));
}

int read_lock(int fd, struct flock *f1, int *ntries)
{
	int count = 0;
try_again:
	if (*ntries == 0) {
		return -1;
	}
	if(fcntl(fd, F_SETLK, f1) == -1) {
		if (errno == EACCES || errno == EAGAIN) {
			D printf("WARN: API %s(), Already locked by another process %s ERROR %d, \n",
					__func__, strerror(errno), errno);
			(*ntries)--;
			count++;
			goto try_again;
		} else {
			fprintf(stderr, "ERR : API %s(), Not able to take lock . %s ERROR %d \n",
					__func__, strerror(errno), errno);
			exit(EXIT_FAILURE);
			//assert(0);
			return -1;
		}
	} else {
		*ntries = count;
		D printf("DBG : API %s(), We got the lock \n", __func__);
		return 0;
	}
}

void read_unlock(int fd, struct flock *f1) 
{
	f1->l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, f1) == -1) {
		fprintf(stderr, "ERR :API %s(), not able to unlock, %s error %d\n",
				__func__, strerror(errno), errno);
		exit(EXIT_FAILURE);
		//assert(0);
	} else {
		D printf("DBG : API %s(), We unlock the lock \n", __func__);
	}
}

/* Initialize the cookies */
read_cookie* read_cookie_init(int fd, size_t total_bytes, size_t read_quanta, int lockit)
{
	fd0 = open(DFILENAME, O_CREAT | O_RDWR);
	read_cookie *rc = NULL;
	/* check the validity of the fd <see more about fcntl() */
	if (!check_read_fd_validity(fd)) {
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
	rc->rc_lockit = lockit;
	return rc;
}

/* Reads the first data. Caller needs to free the memory of char */
char *read_cookie_first(read_cookie *rc)
{
	char *buff = malloc(rc->rc_quanta * sizeof(char));
	int len = 0;
	rc->rc_cur_pos = 0;
	off_t pos;
	/* set current pos to SEEK_SET*/
	pos = lseek(rc->rc_fd, 0, SEEK_SET);
	/* Other way would be to use pread, if I dont want to affect file pos */
	if (buff != NULL) {
		len = read_one_buffer(rc->rc_fd, buff, rc->rc_quanta, rc->rc_cur_pos, rc->rc_lockit);
		rc->rc_bytes_read += len;
		pos = lseek(rc->rc_fd, 0, SEEK_CUR);
		rc->rc_cur_pos = pos;
		D printf("\n DBG: API:%s : Data Read %s and Data len : %d , Data offset : % lld \n", __func__, buff, len, pos);
	} else {
		rc->rc_error = CHAR_NOT_ALLOCATED;
		fprintf(stderr, "ERR: API :%s, Read Buffer Not Allocated \n", __func__);
		D printf(" API: %s :I am getting Buffer Null \n", __func__);
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
		D printf("Warning :File offset is not set to %lld, instead set to %lld \n", rc->rc_cur_pos, pos);
		lseek(rc->rc_fd, SEEK_SET, rc->rc_cur_pos);
		}
	/* Other way would be to use pread, if I dont want to affect file pos */
	if (buff != NULL) {
		len = read_one_buffer(rc->rc_fd, buff, rc->rc_quanta, rc->rc_cur_pos, rc->rc_lockit);
		rc->rc_bytes_read += len;
		pos = lseek(rc->rc_fd, 0, SEEK_CUR);
		rc->rc_cur_pos = pos;
		D printf("\nDBG: API :%s : Data Read %s and Data len : %d , Data offset : % lld \n", __func__, buff, len, pos);
	} else {
		rc->rc_error = CHAR_NOT_ALLOCATED;
		fprintf(stderr, "ERR: API :%s, Read Buffer Not Allocated \n", __func__);
		D printf(" API: %s :I am getting Buffer Null \n", __func__);
		//ASSERT(0);
		exit(EXIT_FAILURE);
		return NULL;
	}
	if (len == 0) {
		rc->rc_cur_pos = rc->rc_end_pos;
	}
	return buff;
}

/* Meat of every read call */
int read_one_buffer(int fd, char *buffer, ssize_t bytes_to_read, off_t pos, int lockit)
{
	int len = bytes_to_read;
	int ret = 0;
	char *temp = buffer; 
	/* check the validity of the fd <see more about fcntl() */
	if (!check_read_fd_validity(fd)) {
		fprintf(stderr,"ERR: API %s, Invalid FD", __func__ );
		exit(EXIT_FAILURE);
		return -1;
	}
	struct flock f1;
	int ntries = 10;
	f1.l_type = F_RDLCK;
	f1.l_whence = SEEK_SET;
	f1.l_start = 0;
	f1.l_len = bytes_to_read;
	f1.l_pid = getpid();
	if (lockit) {
		if (read_lock(fd, &f1, &ntries) == -1) {
			fprintf(stderr, "ERR : API %s() Not able to take read lock", __func__);
			exit(EXIT_FAILURE);
			//assert(0);
			return -1;
		} else {
			D printf("DBG: API: %s Able to take read lock after %d tries \n", __func__, ntries);
		}
	
		/*
		if(fcntl(fd, F_SETLK, &f1) == -1) {
			if (errno == EACCES || errno == EAGAIN) {
				D printf("WARN: API %s(), Already locked by another process %s ERROR %d, \n",
						__func__, strerror(errno), errno);
				goto try_again;
			} else {
				fprintf(stderr, "ERR : API %s(), Not able to take lock . %s ERROR %d \n",
						__func__, strerror(errno), errno);
				exit(EXIT_FAILURE);
				//assert(0);
				return -1;
			}
		} else {
			D printf("DBG : API %s(), We got the lock \n", __func__);
		}
		*/
	}

	/*
	 * case handles
	 * 1. When we are non block and we return 0 and not reading complete data 
	 * 2. When we are interrupted before or while reading data
	 * 3. When we reach EOF, normal case 
	 * 4. Partial Reads <Due to interrupt, being non blocking>
	 */

	D printf("DBG : API : %s, Reading %zd data from offset :%llu \n", __func__, bytes_to_read, pos); 
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
				if (lockit) {
					f1.l_type = F_UNLCK;
					(void) read_unlock(fd, &f1);
				}
				//ASSERT(0);
				exit(EXIT_FAILURE);
				return -1;
			}
			D printf("DBG:API %s We have reading issue \n", __func__);
		} else if(ret == 0) {  /* Either EOF or Call Blocked and returned due to error */
			D printf("\n DBG: API: %s Date completely Read : Data -> %s + Read : %d + Req : %d \n", __func__, buffer, ret, len);
			buffer = temp;
			ret = 0;
		} else {
			len = len - ret;
			if (len != 0) {
				temp  = buffer;
				D printf("\n DBG: API: %s Date Partially Read : Data -> %s , Read : %d  Req : %d \n", __func__, buffer, ret, len);
				buffer = buffer + ret;
			}
		}
	}
	if (ret == 0) {
		D printf("\nDBG : API : %s, Temp : %s and Data : %s \n", __func__, temp, buffer);
	}
	buffer = temp;
	if (ret == 0) {
		D printf("\nDBG : API : %s, Temp : %s and Data : %s \n", __func__, temp, buffer);
	}
	pos = lseek(fd, 0, SEEK_CUR);
	D printf("DBG : API : %s, Read Data : %s --> Size %zd offset :%llu \n", __func__, buffer, bytes_to_read, pos); 

	if (lockit) {
		f1.l_type = F_UNLCK;
		read_unlock(fd, &f1);
	}

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

/* This read is done without affecting the file offset */ 
int read_one_buffer2(int fd, char *buffer, size_t bytes_to_read, off_t pos, int lockit) 
{
	struct flock f1;
	struct stat sb;
	int ret = 0;

	if (!check_read_fd_validity(fd)) {
		fprintf(stderr, "ERR: API :%s, Invalid FD\n", __func__);
		exit(EXIT_FAILURE);
		return -1;
	}

	int ntries = 10;
	f1.l_type = F_RDLCK;
	f1.l_whence = SEEK_SET;
	f1.l_start = 0;
	f1.l_len = bytes_to_read;
	f1.l_pid = getpid();
	if (lockit) {
		if(read_lock(fd, &f1, &ntries) == -1) {
			fprintf(stderr, "ERR: API %s Not able to take read in %d tries \n",
				__func__, ntries);
			exit(EXIT_FAILURE);
			return -1;
		} else {
			D printf("DBG: API %s() able to take lock in %d tries \n", __func__, ntries);
		}
	}

	if (fstat(fd, &sb) < 0) {
		fprintf(stderr,"ERR: API %s, Not able to fstat "
			"%s:Error NO:%d \n", __func__, strerror(errno),
			errno);
		if (lockit) {
			f1.l_type = F_UNLCK;
			read_unlock(fd, &f1);
		}
		//assert(0);
		exit(EXIT_FAILURE);
	}

	if (pos + bytes_to_read > sb.st_size) {
		fprintf(stderr, "ERR : API %s() requested size: %zu  from offset "
			"%lld exceed the total file size %lld\n", __func__,
			bytes_to_read, pos, sb.st_size);
		if (lockit) {
			f1.l_type = F_UNLCK;
			read_unlock(fd, &f1);
		}
		return -1;
	}

	ret = pread(fd, buffer, bytes_to_read, pos);
	if (ret == -1) {
		fprintf(stderr, "ERR: API %s() failed due to pread. %s error %d \n",
			__func__, strerror(errno), errno);
		if (lockit) {
			f1.l_type = F_UNLCK;
			read_unlock(fd, &f1);
		}
		exit(EXIT_FAILURE);
		return -1;
	}
	if (lockit) {
		f1.l_type = F_UNLCK;
		read_unlock(fd, &f1);
	}
	return ret;
}


