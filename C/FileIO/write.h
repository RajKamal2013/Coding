#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <assert.h>
#include "debug.h"

int check_write_fd_validity(int fd);
int write_one_buffer(int fd, char *buffer, ssize_t size, int lockit);
int write_one_buffer2(int fd, char *buff, ssize_t size, off_t pos, int lockit);

