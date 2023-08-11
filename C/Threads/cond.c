#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include "debug.h"


typedef struct my_cond_ {
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	int val;
} my_cond;


my_cond data = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER, 0 };

int hibernation = 1;

void * wait_thread(void *arg) 
{
	int status;


	sleep(hibernation);

	status = pthread_mutex_lock(&data.mutex);
	if (status != 0) {
		err_abort(status, "Mutex Lock ");
	} 

	data.val = 1;
	
	/* sigmal main to do its work */
	status = pthread_cond_signal(&data.cond);

	if (status != 0)  {
		err_abort(status, "Cond Signal ");
	}

	status = pthread_mutex_unlock(&data.mutex);
	if (status != 0) {
		err_abort(status, "Mutex Unlock ");
	}
	
	return NULL;
}

int main(int argc, char *argv[]) 
{
	int status;
	pthread_t wait_thread_id;
	struct timespec timeout;

	if (argc > 1) {
		hibernation = atoi(argv[1]);
	}
	
	timeout.tv_sec = time(NULL) + 10;
	timeout.tv_nsec = 0;

	status = pthread_create(&wait_thread_id, NULL, wait_thread, NULL);

	if (status != 0) {
		err_abort(status, "Pthread create Failed ");
	}

	status = pthread_detach(wait_thread_id);

	if (status != 0) {
		err_abort(status, "Detach Failed ");
	}

	status = pthread_mutex_lock(&data.mutex);
	if (status != 0) {
		err_abort(status, "Mutex Lock ");
	} 

	while(data.val == 0) {
		status = pthread_cond_timedwait(&data.cond, &data.mutex, &timeout);
		if (status  == ETIMEDOUT) {
			printf("Condition Wait Timedout \n");
			break;
		}
		else if (status != 0) {
			err_abort(status, "Waiting on Condition ");
		} else {
			printf (" My wait is done ");
		}
	}

	if (data.val != 0) {
		printf("Condition was Signalled \n");
	}

	status = pthread_mutex_unlock(&data.mutex);
	if (status != 0) {
		err_abort(status, "Unlock Mutex ");
	}
	return 0;
}

