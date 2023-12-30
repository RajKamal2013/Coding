#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/types.h>

#define BUFFER_SIZE 128
#define TIMEOUT 10

/*
 * struct pollfd {
 * 	int fd;
 * 	short events;
 * 	short revents;
 * }
 * events -> event to witness 
 * revents -> events retutned.
 * events -> POLLIN, <POLLRDBAND, POLLRDNORM>
 * 	     POLLOUT, <POLLWRNORM, POLLWRBAND>
 *	     POLLMSG  -> SIGPOLL Message is available
 *	     POLLPRI -> high pri
 * revents -> 0 or Error -> POLLER, POLLHUP, POLLNVAL 
 * 	   -> these are returned in revents !!
 * Select read -> POLLIN | POLLPRI 
 * select write -> POLLOUT | POLLWRBAND
 * POLLIN -> Readble without blocking 
 * POLLOUT -> writable without blocking
 * POLLIN || POLLOUT  -> Both read and write events 
 * int poll (struct pollfd *fds, nfds_t nfds, int timeout)
 * 	timeout -> time to wait (-1 -> inifinite time )
 * Error -> EBADF, EFAULT, EINTR, EINVAL, ENOMEM
 */

int main()
{
	struct pollfd fd[2];
	int ret = 0;
	fd[0].fd = STDIN_FILENO;
	fd[0].events = POLLIN;

	fd[1].fd = STDOUT_FILENO;
	fd[1].events = POLLOUT;

	ret = poll(fd, 2, 1000 *TIMEOUT);
	if (ret == -1) {
		perror("Error: Poll");
		return 1;
	}
	if (!ret) {
		printf("Time Elapsed In seconds : %d \n", TIMEOUT);
	}

	if (fd[0].revents & POLLIN) {
		printf("FD is readable ");
	} 

	if (fd[1].revents & POLLOUT) {
		printf("FD is writable ");
	}

	return 0;
}
