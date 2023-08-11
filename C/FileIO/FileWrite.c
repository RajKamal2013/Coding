#include "write.h"


int main(int argc, char *argv[]) 
{
	char *fileName;
	int fd;
	struct stat sb;
	size_t size;
	int ret = -1;
	char *write_buff;
	if (argc < 2) {
		printf ("Enter the fileName : ");
		/*
		 * We can wait for some time and then we can quit, I need to add that 
		 * intelligence. pollfd might be a good way. Lets do it later. 
		 */
		scanf("%s", fileName);
	} else {
		fileName = argv[1];
		if (1 == sscanf(argv[2], "%zu", &size))
		D printf("DBG: API %s(), Need to write %zu bytes ", __func__, size);
	
		/* actually we dont need to use write buff */
		write_buff = malloc(size);
		if (write_buff != NULL) {
			write_buff = (char *)write_buff;
			strncpy(write_buff, argv[3], size);
		} else {
			fprintf(stderr, "ERR : API %s() not able to allocate write buffer \n",
				__func__);
			exit(EXIT_FAILURE);
			//assert(0);
		}
	}

	printf("FileName is %s \n", fileName);

	fd = open(fileName, O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	if (fd == -1) {
		fprintf(stderr,"ERR:API %s, Not able to open %s File %s Error NO:%d\n",
				__func__, fileName, strerror(errno), errno);
		//assert(0);
		exit(EXIT_FAILURE);
	}

	ret = write_one_buffer(fd, write_buff, size, 1);
	//ret = write_one_buffer(fd, argv[3], size, 0);
	if (ret == -1) {
		fprintf(stderr, "ERR: API %s(), write failed \n", __func__);
		exit(EXIT_FAILURE);
	} else {
		D printf("DBG : APP %s() wrote %d bytes , Req Byte: %ld\n", __func__, ret, size);
	}

	printf("\n");
	if (fstat(fd, &sb) < 0) {
		fprintf(stderr,"ERR: API %s, Not able to fstat on %s File,"
			"%s:Error NO:%d \n", __func__, fileName, strerror(errno),
			errno);
		//assert(0);
		exit(EXIT_FAILURE);
	}

	printf("Total Bytes in the file %s is %lld \n", fileName, sb.st_size);
	printf("Inode of the file %s is %llu \n", fileName, sb.st_ino);

	printf("Using pwrite with advisory lock \n");
	ret = write_one_buffer2(fd, argv[3], size, size, 1);

	if (write_buff != NULL) {
		free(write_buff);
		write_buff = NULL; // Dont make it dangling please 
	}

	close(fd);

	return 0;
}

