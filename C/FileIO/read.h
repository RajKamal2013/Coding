#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#include "debug.h"


#define DFILENAME "DebugRead.txt"
#define CHAR_NOT_ALLOCATED 1


int fd0;

typedef struct read_cookie_ 
{
	int rc_fd;
	size_t rc_bytes_read;
	size_t rc_quanta;
	size_t rc_total_bytes;
	off_t rc_cur_pos;
	off_t rc_end_pos;
	int rc_error;
	int rc_lockit;
} read_cookie;


read_cookie * read_cookie_init(int fd, size_t total_bytes, size_t read_quanta, int lockit);
char* read_cookie_first(read_cookie *cookie);
char* read_cookie_next(read_cookie *cookie, char *buf);
int read_one_buffer(int fd, char *buffer, ssize_t len, off_t pos, int lockit);
//int read_n_buffer(int fd, char **buffer, ssize_t len, int n);
int read_cookie_free(read_cookie *rc);
int check_read_fd_validity(int fd);
int read_lock(int fd, struct flock *f1, int *ntries);
void read_unlock(int fd, struct flock *f1);
int read_one_buffer2(int fd, char *buffer, size_t bytes, off_t pos, int lockit);

