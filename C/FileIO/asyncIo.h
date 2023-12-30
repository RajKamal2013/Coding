/* One proces will lock the file using advisary lock. Next one will do asyncIo */

/* <---------- aio_suspend, aio_read, aio_return -------------> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <aio.h>


//int do_async_read(int fd, char **buffer, int quanta, int count, int offset);

/* APIs doing Asyncio */

void write_to_file(int fd, void *buf, size_t size, off_t offset, int count);
void write_to_file_async(int fd, void *buf, size_t size, off_t offset, int count);
void read_from_file(int fd, void *buf, size_t size, off_t offset, int count);
void read_from_file_async(int fd, void *buf, size_t size, off_t offset, int count);
int check_file_validity(int fd);
void do_wait(struct aiocb **cb_list, int count);
