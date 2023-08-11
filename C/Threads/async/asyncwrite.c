/* Creates 5 files consist for integers which is will be input for batch sorting */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <aio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include "debug.h"
#include "driver.h"

char* fileNames[FILE_COUNT]= {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};

<<<<<<< HEAD
/* fcntl -> F_GETFD fails and errno is set to E_BADF -> file is not available */
int check_file_validity(int fd) 
=======
int check_fd_validity(int fd)
>>>>>>> 98f82d61e86da817980e95382f3b7c6fd81f643a
{
	return ((fcntl(fd, F_GETFD) != -1) || (errno != EBADF));
}

/* TODO :- need a scalable code (more of dynamic ) */
void signal_the_thread(int filedes) 
{
	int id;
	if (filedes == fd[0]) {
		id = 0;
	} else if (filedes == fd[1]) {
		id = 1;
	} else if (filedes == fd[2]) {
		id = 2;
	} else if (filedes == fd[3]) {
		id = 3;
	} else if (filedes == fd[4]) {
		id = 4;
	} else {
		/*GOT wrong file handle */
		abort();
	}

	/* signal the waiting thread */
	pthread_mutex_lock(&fd_mutex[id]);
	fd_complete[id] = 1;
	pthread_cond_signal(&fd_cv[id]);
	pthread_mutex_unlock(&fd_mutex[id]);
}

/* Called once data is generated in the file , so that we can sort the data further */
/*
void fd_aio_completion_handler(sigval_t sigval)
{
	struct aiocb *req;
	int ret;
	req = (struct aiocb *)sigval.sival_ptr;

	if (aio_error(req) == 0) {
		ret = aio_return(req);
		printf ("Return of Async Write : %d \n", ret);
		signal_the_thread(req->aio_fildes);
	}
	return;
}
*/

void send_data_to_file(int fd)
{
	int arr[ARRAY_SIZE], i, ret, go_on;
	struct aiocb fd_aiocb[1];
	struct aiocb *fd_aiocb_list[1];

	ret = check_file_validity(fd);
	if (!ret) {
		err_abort(ret, "File Validatity fails ");
	}
	for (i = 0;i < ARRAY_SIZE; i++) {
		arr[i] = rand() % ARRAY_LIMIT;
	}

	bzero(&fd_aiocb[0], sizeof(struct aiocb));
	fd_aiocb[0].aio_fildes = fd;
	fd_aiocb[0].aio_buf = arr;
	fd_aiocb[0].aio_nbytes = sizeof(arr);
	fd_aiocb[0].aio_offset = 0;
	fd_aiocb_list[0]= &fd_aiocb[0];

	/*
	fd_aiocb.aio_sigevent.sigev_notify = SIGEV_THREAD;
	fd_aiocb.aio_sigevent.sigev_notify_function = fd_aio_completion_handler;
	fd_aiocb.aio_sigevent.sigev_notify_attributes = NULL;
	fd_aiocb.aio_sigevent.sigev_value.sival_ptr = &fd_aiocb;
	*/


	if (!check_fd_validity(fd))
	{
		printf("bad Fd \n");
		
	}
	ret = aio_write(fd_aiocb_list[0]);
	if (ret != 0) {
		abort();
		perror("aio_write() ");
	}

	printf("Return of aio_write ( ) is %d \n", ret);

	go_on = 0;
	do {
		aio_suspend(fd_aiocb_list, 1, NULL);
		if (aio_error(fd_aiocb_list[0]) == EINPROGRESS) {
			go_on = 1;
		}
	} while (go_on);
	printf ("Completed the write ");
}

void prepare_data_async() 
{
	int i = 0;
	for ( i = 0; i < FILE_COUNT; i++) {
		printf("File : %s \n", fileNames[i]);
		fd[i] = open(fileNames[i], O_APPEND | O_CREAT , S_IRWXU);
		if (fd[i] == -1 ) {
			printf("Not able to create file \n");
		}
		send_data_to_file(fd[i]);
	}
}

void *thread_func(void *arg)
{
	int *fd = (int *)arg;
	//int arr[ARRAY_SIZE];
	printf("File Done : %d \n", *fd);
	return NULL;
}


/* This API spawn thread to sort data in file and dump to the file */
void dump_to_file_and_sort() 
{
	int i = 0;
	int status = 0;

	for (i = 0; i < FILE_COUNT; i++) {
		/* FIle should be already opened */
		if (fd[i] == -1) {
			abort();
		}

		fd_complete[i] = 0;

		status = pthread_mutex_init(&fd_mutex[i], NULL);
		if (status != 0) {
			err_abort(status, "Mutex initialize failed");
		}

		status = pthread_cond_init(&fd_cv[i], NULL);
		if (status != 0) {
			err_abort(status, "Cv initialize failed");
		}

		status = pthread_create(&fd_tid[i], NULL, thread_func, (void *)&fd[i]);

		if (status != 0) {
			err_abort(status, "Thread Creation Failed for mergeSort ");
		}
	}
	/* free up the resoures */
	for (i = 0; i < FILE_COUNT; i++) {
		status = pthread_join(fd_tid[i], NULL);
		if (status != 0) {
			err_abort(status, "Join Thread Failed");
		}

		status = pthread_mutex_destroy(&fd_mutex[i]);
		if (status != 0) {
			err_abort(status, "Pthread_mutex_destroy Failed ");
		}
		status = pthread_cond_destroy(&fd_cv[i]);
		if (status != 0) {
			err_abort(status, "Pthread_cv_destroy Failed ");
		}
		/* close the file now */
		fsync(fd[i]);
		close(fd[i]);
	}

	printf ("we are end dumping to file ! please check the file \n");
}

