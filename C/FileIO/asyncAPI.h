#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fnctl.h>
#include <signal.h>
#include <errno.h>
#include <aio.h>
#include <sys/types.h>
#include <sys/stats.h>
#include <sys/wait.h>


typdef enum error_s {
	E_BAD_FD =0,

} error_t;

/* APIs */

error_t read_from_file_async(int fd, int quanta, size_t offset, size_t size, void *buf);
void write_to_file_async(int fd, int quanta, size_t offset, size_t size, void *buf);
void do_wait();
void driver();
int check_file_validity(int fd);

int check_file_validity(int fd) 
{
	return (((fcntl(fd, F_GETFD) != -1) && (errno != EBADF));
}

int read_from_file_async(int fd, int quanta, size_t offset, size_t size, void *buf, int lockit)
{

/*
 * 1. check file validity.
 * 2. lock the file.
 * 3. send aio to read
 * 4. wait for aio to complete
 * 5. return the buffer read.
 */


}


