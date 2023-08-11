#include "write.h"

int check_write_fd_validity(int fd) 
{
	return ((fcntl(fd, F_GETFD) != -1) || (errno != EBADF));
}

int write_lock(int fd, struct flock *f1, int* ntries ) 
{
	int count = 0;
try_again:
	if ((*ntries) == 0)   {
		fprintf(stderr, "ERR: API %s() not able to take write lock in %d tries\n",
				__func__, count);
		return -1;
	}

	if(fcntl(fd, F_SETLK, f1) == -1) {
		if (errno == EACCES || errno == EAGAIN) {
			D printf("WARN: API %s(), Already locked by another process %s ERROR %d, \n",
					__func__, strerror(errno), errno);
			(*ntries)--;
			count++;
			goto try_again;
		} else {
			fprintf(stderr, "ERR : API %s(), Not able to take lock . %s ERROR %d \n",
					__func__, strerror(errno), errno);
			exit(EXIT_FAILURE);
			//assert(0);
			return -1;
		}
	} else {
		*ntries = count;
		D printf("DBG : API %s(), We got the lock \n", __func__);
		return 0;
	}
}

void write_unlock(int fd, struct flock *f1) 
{
	f1->l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, f1) == -1) {
		fprintf(stderr, "ERR :API %s(), not able to unlock, %s error %d\n",
				__func__, strerror(errno), errno);
		exit(EXIT_FAILURE);
		//assert(0);
	} else {
		D printf("DBG : API %s(), We unlock the lock \n", __func__);
	}
}


int write_one_buffer(int fd, char *buffer, ssize_t size, int lockit)
{
	if (!check_write_fd_validity(fd)) {
		fprintf(stderr, "ERR: API:%s(), fd is invalid \n", __func__);
	}
	int ret;
	long len = size;
	struct flock f1;
	int ntries = 10;

	if (lockit) {
		f1.l_type = F_WRLCK;
		f1.l_whence = SEEK_SET;
		f1.l_start = 0;
		f1.l_len = size;
		f1.l_pid = getpid();

		if((write_lock(fd, &f1, &ntries)== -1)) {
			fprintf(stderr, "ERR: API %s() not able to take write lock \n", __func__);
			exit(EXIT_FAILURE);
		} else {
			D printf("DBG : API %s(), We got the lock after %d tries\n", __func__, ntries);
		}
	}
	while ( (len != 0) && ((ret = write(fd, buffer, len)) != 0)) {
		if (ret == -1) {
			if (errno == EINTR) {
				continue; 
			} else {
				fprintf(stderr, "ERR: API %s(), write failed \n", __func__);
				f1.l_type = F_UNLCK;
				write_unlock(fd, &f1);
				exit(EXIT_FAILURE);
				//assert(0);
				return -1;
			}
		} else {
			len -= len;
			buffer += len;
		}
	}
	if (lockit) {
		f1.l_type = F_UNLCK;
		write_unlock(fd, &f1);
	}
	/* Now sync the data */
	if (fsync(fd) == -1) {
		fprintf(stderr, "ERR: API %s(), not able to flush the data. %s error %d \n",
			__func__, strerror(errno), errno);
		exit(EXIT_FAILURE);
		//assert(0);
		return ret;
	}
	return ret;
}


int write_one_buffer2(int fd, char *buff, ssize_t size, off_t pos, int lockit)
{
	int ret = -1;
	/* Check buffer is not NULL */
	if (buff == NULL) {
		fprintf(stderr, "ERR: API %s() Nothing to write \n", __func__);
		return -1;
	}

	/* Checking the validity of FD */
	if (!check_write_fd_validity(fd)) {
		fprintf(stderr, "ERR: API %s (), fd is invalid \n", __func__);
		exit(EXIT_FAILURE);
		return -1;
	}
	/* take advisary lock for the segment of file */
	struct flock f1;
	int ntries = 10;
	if (lockit) {
		f1.l_type = F_WRLCK;
		f1.l_whence = SEEK_SET;
		f1.l_start = 0;
		f1.l_len = size;
		f1.l_pid = getpid();

		if ((ret = write_lock(fd, &f1, &ntries)) == -1) {
			fprintf(stderr, "ERR:API %s(), Not able to advisary lock after %d retries \n", 
				__func__, ntries );
			exit(EXIT_FAILURE);
		}else {
			D printf("Got Write lock after %d tries \n", ntries );
		}
	}

	int pwrite_retry = 10;
try_again:
	if (pwrite_retry == 0) {
		return -1;
	}
	/* Dont worry about file descriptor , ITS PWRITE !!! */
	if ((ret = pwrite(fd, buff, size, pos)) == -1) {
		if (errno == EAGAIN || errno == EINTR) {
			pwrite_retry--;
			goto try_again;
		} else {
			fprintf(stderr, "ERR: API %s(), serious issue with pwrite, %s Error %d \n",
				__func__, strerror(errno), errno);
			return -1;
		}
	} 
	return ret;
}


