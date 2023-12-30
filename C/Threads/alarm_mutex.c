#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pthread.h>
#include "debug.h"


typedef struct  alarm_
{
	struct alarm_ *link;
	int seconds;
	time_t time;
	char msg[64];
}alarm_t;

pthread_mutex_t alarm_mutex = PTHREAD_MUTEX_INITIALIZER;

alarm_t *alarm_list = NULL;

void* thread_func(void *arg)
{
	alarm_t *alarm;
	int sleep_time;
	time_t now;
	int status;

	status = pthread_detach(pthread_self());
	if (status != 0) {
		err_abort(status, "Detach Failed ");
	}

	while(1) {
		/* Take the lock */
		status = pthread_mutex_lock(&alarm_mutex);
		if (status != 0) {
			err_abort(status, "Lock Failed \n");
		}

		/* Get the head of the list */
		alarm = alarm_list;

		if (alarm == NULL) {
			sleep_time = 1;
		} else {
			alarm_list = alarm->link;
			now = time(NULL);
			if (alarm->time <= now) {
				sleep_time = 0;
			} else {
				sleep_time = alarm->time - now;
			}
		}

		status = pthread_mutex_unlock(&alarm_mutex);
		if (status != 0) {
			err_abort(status, "Unlock failed");
		}

		if (sleep_time > 1) {
			sleep(sleep_time);
		} else {
			sched_yield();		/* The case where alarm is already expired <oops waited a lot */
		}

		if (alarm != NULL) {
			printf("%d %s \n", alarm->seconds, alarm->msg);
			free(alarm);
			alarm = NULL; /* I dont want dangling pointer */
		}
	}
}

int main()
{
	char line[128];
	alarm_t **last, *next, *alarm;
	pthread_t tid;
	int status;

	status = pthread_create(&tid, NULL,  thread_func, alarm_list);
	if (status != 0 ) {
		err_abort(status, "Thread creation failed ");
	}

	while(1) {
		if ((fgets(line, sizeof(line), stdin) == NULL)) {
			exit(0);
		}

		if (strlen(line) <= 1) {
			continue;
		}

		alarm = malloc(sizeof(alarm_t));
		if (alarm == NULL) {
			err_abort(errno, "Malloc Failed ");
		} else {
			alarm = (alarm_t *)alarm;
		}

		if (sscanf(line, "%d %64[^\n]", &alarm->seconds, alarm->msg) != 2) {
			fprintf(stderr, "ERR : API() %s:%d, Bad Command.%s error %d",
				__func__, __LINE__, strerror(errno), errno);
			free(alarm);
		} else {
			status = pthread_mutex_lock(&alarm_mutex);
			if (status != 0) {
				err_abort(status, "Mutex Lock Failed ");
			}
			alarm->time = alarm->seconds + time(NULL);
			last = &alarm_list; 
			next = *last;

			/* Insert the alarm in sorted order */
			while (next != NULL) {
				if (alarm->time <= next->time) {
					alarm->link = next;
					*last = alarm;
					break;
				} 
				last = &(next->link);
				next = next->link;
			}
			if (next == NULL) {
				*last = alarm;
				alarm->link = NULL;
			}
			status = pthread_mutex_unlock(&alarm_mutex);
			if (status != 0) {
				err_abort(status, "Mutex Unlock Failed");
			}
		}
	}
	return 0;
}


