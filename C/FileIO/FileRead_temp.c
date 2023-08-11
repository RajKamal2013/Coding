#include "read.h"

#define READ_QUANTA 128

int main(int argc, char *argv[]) 
{
	char *fileName;
	int fd;
	read_cookie *rc = NULL;
	struct stat sb;
	char *read_buff;
	if (argc < 2) {
		printf ("Enter the fileName : ");
		/*
		 * We can wait for some time and then we can quit, I need to add that 
		 * intelligence. pollfd might be a good way. Lets do it later. 
		 */
		scanf("%s", fileName);
	} else {
		fileName = argv[1];
	}

	printf("FileName is %s \n", fileName);

	fd = open(fileName, O_RDONLY | O_SYNC, S_IRUSR | S_IRGRP | S_IROTH);
	if (fd == -1) {
		fprintf(stderr,"ERR:API %s, Not able to open %s File %s Error NO:%d\n",
				__func__, fileName, strerror(errno), errno);
		//assert(0);
		exit(EXIT_FAILURE);
	}

	if (fstat(fd, &sb) < 0) {
		fprintf(stderr,"ERR: API %s, Not able to fstat on %s File,"
			"%s:Error NO:%d \n", __func__, fileName, strerror(errno),
			errno);
		//assert(0);
		exit(EXIT_FAILURE);
	}
	
	printf("Total Bytes in the file %s is %lld \n", fileName, sb.st_size);
	printf("Inode of the file %s is %llu \n", fileName, sb.st_ino);
	rc = read_cookie_init(fd, sb.st_size,  READ_QUANTA);
	
	if (rc == NULL) {
		fprintf(stderr,"ERR: API %s, Read Cookie Initialize Failed", __func__);
		//assert(0);
		exit(EXIT_FAILURE);
	}
/*
	read_buff = malloc(READ_QUANTA * sizeof(char));
	if (read_buff == NULL) {
		fprintf(stderr,"Err: API:%s, Malloc Failed for read buffer, "
			"%s:Error NO:%d\n", __func__, strerror(errno), errno);
		//assert(0);
		exit(EXIT_FAILURE);
	}
*/
	
	for (read_buff = read_cookie_first(rc); (rc->rc_cur_pos != rc->rc_end_pos);
	     read_buff = read_cookie_next(rc, read_buff)) {
	//	printf("DBG : API :%s Data MetaData : %llu Current offset, %zu Bytes Read \n", __func__, rc->rc_cur_pos, rc->rc_bytes_read);
	//	printf("DBG : API : %s Data Read : %s ", __func__, read_buff);
		printf("%s", read_buff);
	}
	printf("%s", read_buff);
//	printf ("\n DBG: API %s, Final Read -> %s \n", __func__, read_buff);
	free(read_buff);
	read_buff = NULL;

	printf("\n");

	if (read_buff != NULL) {
		free(read_buff);
		read_buff = NULL; /* Dont make it dangling please */
	}

	close(fd);

	return 0;
}

