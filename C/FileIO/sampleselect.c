#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>

#define TIMEOUT 30

int main() 
{
	fd_set readfds;
	struct timeval tv;
	int ret = 0;

	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);

	tv.tv_sec = TIMEOUT;
	tv.tv_usec = 0;

	ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv);

	if (ret < 0 ) {
		perror("Error: Select()");
		exit(EXIT_FAILURE);
	} else if(!ret) {
		printf ("%ld Seconds Elapsed \n", tv.tv_sec);
	}

	char buff[128]; 
	ssize_t nr = 0;
	int size = 128;

	if (FD_ISSET(STDIN_FILENO, &readfds)) {
		nr = read(0, buff, size);
		if (nr < 0 ) {
			if (errno == EINTR) {
				perror("Error :Interrupt");
			} else if (errno == EAGAIN) {
				perror("Error : Try Again ");
			} else {
				perror("Error :SERIOUS !");
				exit(EXIT_FAILURE);
			}
			printf("Buffer Read : %s \n", buff);
		}
	}

	printf("TIME ELAPSED : %ld \n", tv.tv_sec);

	return 0;
}

