#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>    /* Perror */
#include <errno.h>
#include <stdlib.h>
#include <string.h>


#define BUFFER_SIZE 128

void sampleread(int fd )
{
	ssize_t nr;
	char buff[BUFFER_SIZE];
	nr = read(fd, buff, BUFFER_SIZE);
	if (nr < 0) {
		perror("Error: Read Failed ");
		exit(EXIT_FAILURE);
	}
	printf("Data Read : %s \n", buff);
}


void optimize_read_buffer(int fd)
{
	ssize_t ret = 0;
	long len = BUFFER_SIZE;
	char *buff = (char *)malloc(BUFFER_SIZE);

start:
	while ( (len != 0) && ((ret = read(fd, buff, len)) !=  0)) {
		if (ret == -1) {
			if (errno == EINTR)  {
				perror("Read Error :Interrupt ");
			} else if (errno == EAGAIN) {
				goto start;
			} else {
				perror("Reea Error !!");
			}
		}
		if (ret < len) {
			len = len - ret;
		}
		printf("%s", buff);
		(void)memset(buff, '\0', ret);

	}
}

int main() 
{
	int fd;
	fd = open("file.txt", O_RDONLY | O_NONBLOCK, S_IRUSR | S_IRGRP | S_IROTH);
	if (fd < 0) {
		perror("Error : File Not Found ");
		exit(EXIT_FAILURE);
	}
	optimizeread(fd);
//	sampleread(fd);
/*	This is Error as test var has no size  */
	/*
	ssize_t nr;
	char *test = "none of this is right";
	nr = read(fd, test, ARRAY_SIZE);
	if (nr < 0) {
		perror("Error: Read Failed ");
		exit(EXIT_FAILURE);
	}
	printf("Data Read : %s \n", test);
*/
	return 0;

}
