#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <aio.h>

#include "asyncIo.h"
#include "debug.h"

/*-------------Note -> things to DO -------------------------*/
//1. Complete the aio_read for more than one count 
//2. Aio_Write( ) and aio_read() for other than multiples of 4 
/*-----------------------------------------------------------*/

/* This checks for file validity */
int check_file_validity(int fd)
{
	return ((fcntl(fd, F_GETFD) != -1 ) && (errno != EBADF));
}

void do_wait(struct aiocb **cb_list, int count)
{
	/* Wait for AIO to complete <Suspend and wake as it gets over >*/
	int go_on = 0;
	int i, status;
	do {
		status = aio_suspend((const struct aiocb *const *)cb_list, count, NULL);
		if (status  != 0) {
		     errno_abort("AIO suspend failed ");
		}
		for (i = 0; i < count;  i++) {
			if (cb_list[i] != NULL) {
				status = aio_error(cb_list[i]);
				if (status == EINPROGRESS) {
					go_on = 1;
				} else {
					status = aio_return(cb_list[i]);
					if (status == -1) {
						errno_abort("AIO RETURN failed ");
					}
				}
				cb_list[i] = NULL;
			}
		}
	}while(go_on);
	printf ("Done waiting !! AIO Completed \n");
}


/*----------------------------- Asynchronous IO -----------------------------------*/
/* File should be opened in append mode */
void write_to_file_async(int fd, void *buf, size_t size, off_t offset, int count)
{
	if (!check_file_validity(fd)) {
		err_abort(EBADF, "File Validity Failed ! ");
	}

	struct aiocb cb[count];
	struct aiocb *cb_list[count];
	int i;
	size_t quanta = size/count;
	size_t pos = 0;
	size_t off = offset;

	printf("Writing Data Async : Size :%ld quantum :%ld  Offset :%ld times in Count : %d \n", size, quanta, offset, count);

	for (i = 0; i < count; i++) {
		bzero(&cb, sizeof(struct aiocb));
		cb[i].aio_fildes = fd;
		cb[i].aio_buf  = buf +  pos;
		cb[i].aio_nbytes = quanta;
		cb[i].aio_offset = off;
		cb[i].aio_reqprio = 0;
		//cb[i].aio_offset = 0;
		off = off + quanta;
		pos = pos + quanta;
		cb[i].aio_sigevent.sigev_notify=SIGEV_NONE;

		cb_list[i] = &cb[i];
	}

	for (i = 0; i < count; i++) {
		if ((aio_write(cb_list[i]) < 0 ) && (errno == ENOSYS)) {
			errno_abort("No AIO Support in system ");
		}
	}

	do_wait(cb_list, count);

	printf ("Done Async writing to File \n");
}

/* Note -> Need to fix for count > 1 */
void read_from_file_async(int fd, void *buf, size_t size, off_t offset, int count)
{
	if (!check_file_validity(fd)) {
		errno_abort("Invalid File Handle ");
	}

	struct aiocb cb[count];
	struct aiocb *cb_list[count];
	int i;
	size_t quanta = size/count;
	size_t pos, off;

	printf("Reading Data Async :- Size : %ld , Qunta : %ld offset :%ld Count :%d \n", size, quanta, offset, count);

	pos = 0;
	off = lseek(fd, offset, SEEK_SET);

	for (i = 0; i < count; i++) {
		bzero(&cb, sizeof(struct aiocb));
		cb[i].aio_fildes = fd;
		cb[i].aio_buf  = (buf + pos);
		cb[i].aio_nbytes = quanta;
		cb[i].aio_offset = off;
		cb[i].aio_reqprio = 0;
		//cb[i].aio_offset = 0;
		off = off + quanta;
		pos = pos + quanta;
		cb[i].aio_sigevent.sigev_notify=SIGEV_NONE;

		cb_list[i] = &cb[i];
	}

	for (i = 0; i < count ; i++) {
		if ((aio_read(cb_list[i]) < 0 ) && (errno == ENOSYS)) {
			errno_abort("No AIO Support in system ");
		}
	}

	do_wait(cb_list, count);

	printf ("Done Async Reading from File \n");
}

/*<------------------------Asynchronous IO -------------------------------->*/


/*<---------------------- Synchronous IO ----------------------------------->*/
void write_to_file(int fd, void *buf, size_t size, off_t offset, int count)
{
	if (!check_file_validity(fd)) {
		errno_abort("Invalid File Handle ");
	}

	int i;
	size_t quanta = size/count;
	int pos;

	lseek(fd, offset, SEEK_SET);
	printf("Writing Data sync :- Size : %ld , Qunta : %ld offset :%ld Count :%d \n", size, quanta, offset, count);

	for (i = 0; i < count; i++) {
		pos = i * quanta;
		write(fd, buf + pos, quanta);
	}
	printf("Done Writing to File Synchronously \n");
}

void read_from_file(int fd, void *buf, size_t size, off_t offset, int count)
{
	if (!check_file_validity(fd)) {
		errno_abort("Invalid File Handle ");
	}

	int i, pos;
	size_t quanta = size/count;

	printf("Reading Data sync :- Size : %ld , Qunta : %ld offset :%ld Count :%d \n", size, quanta, offset, count);
	lseek(fd, offset, SEEK_SET);
	for (i = 0; i < count; i++)
	{
		pos = i * quanta;
		read(fd, buf + pos, quanta);
		printf("Buffer Read : %d \n", *((int *)(buf + pos)));
	}
	printf("Done Reading From File \n");

}

/*<---------------------------- Synchronous IO --------------------------------->*/

