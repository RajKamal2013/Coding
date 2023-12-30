#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "debug.h"


void * thread_routine(void *arg)
{
	printf("I created a thread and it says %s \n", (char *)arg);
	return arg;
}

int main()
{
	pthread_t thread_id;
	void *thread_result;
	int status;
	char buffer[] = "Its me ";

	status = pthread_create(&thread_id, NULL, thread_routine, buffer);
	if (status != 0) {
		err_abort(status, "ERR: Our pthread_create() failed \n");
	}

	status = pthread_join(thread_id, &thread_result);
	if (status != 0) {
		err_abort(status, "Join Status ");
	}

	if (thread_result == NULL) {
		return 0;
	} else {
		return 1;
	}

	return 0;
}


