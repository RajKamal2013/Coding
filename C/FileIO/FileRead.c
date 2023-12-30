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
	rc = read_cookie_init(fd, sb.st_size,  READ_QUANTA, 1);
//	rc = read_cookie_init(fd, sb.st_size,  READ_QUANTA, 0);
	
	if (rc == NULL) {
		fprintf(stderr,"ERR: API %s, Read Cookie Initialize Failed", __func__);
		//assert(0);
		exit(EXIT_FAILURE);
	}
	
	for (read_buff = read_cookie_first(rc); (rc->rc_cur_pos != rc->rc_end_pos);
	     read_buff = read_cookie_next(rc, read_buff)) {
		D printf("DBG : API :%s Data MetaData : %llu Current offset, %zu Bytes Read \n", __func__, rc->rc_cur_pos, rc->rc_bytes_read);
		D printf("DBG : API : %s Data Read : %s ", __func__, read_buff);
		printf("%s", read_buff);
	}
	printf("%s", read_buff);
	D printf ("\n DBG: API %s, Final Read -> %s \n", __func__, read_buff);

	printf("\n");

	printf ("Reading via pread \n");
	
	char *buff = malloc(50 *sizeof(char));
	if (buff == NULL) {
		fprintf(stderr, "ERR: API %s()  -> malloc failed \n", __func__);
		exit(EXIT_FAILURE);
	} 
	int ret = -1;
	if ((ret = read_one_buffer2(fd, buff, 49, 10, 1)) == -1 ) {
		fprintf(stderr, "ERR : API %s() read_one_buffer2() issue \n", __func__);
		exit(EXIT_FAILURE);
	} else {
		printf("-----Data Via Pread ----\n");
		printf("%s \n", buff);
	}

	if (buff != NULL) {
		free(buff);
		buff = NULL;
	}

	if (read_buff != NULL) {
		free(read_buff);
		read_buff = NULL; /* Dont make it dangling please */
	}

	close(fd);
	return 0;
}

