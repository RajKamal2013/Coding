#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include "debug.h"


typedef struct alarm_{
	struct alarm_ *link;
	int seconds;
	time_t time;
	char msg[64];
}alarm_t;

pthread_mutex_t alarm_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t alarm_cond = PTHREAD_COND_INITIALIZER;
time_t current_alarm = 0;
alarm_t *alarm_list = NULL;


/* Here I am goint to insert alarn to alarm list and then signal */
/* this is signal function */
/* We will have already acquired mutex */
void alarm_insert(alarm_t *alarm)
{
	alarm_t **last, *next;
	int status;

	/* get the pointers */
	last =  &alarm_list;
	next = *last;

	/* check we have alarm allocated or not */
	if (alarm == NULL) {
		return ;
	}

	/* get to place where we are inserting */
	while (next != NULL) {
		/* alarm time is less than the front */
		if (alarm->time <= next->time) {
			alarm->link = next;
			*last = alarm;
			break;
		}
		last = &next->link;
		next = next->link;
	}
	if (next == NULL) {
		*last = alarm;
		alarm->link = NULL;
	}

	/* Means alarm is empty or alarm inserted is less than the last time inserted */
	if (current_alarm == 0 || alarm->time < current_alarm) {
		current_alarm = alarm->time;
		status = pthread_cond_signal(&alarm_cond);
		if (status != 0) {
			err_abort(status, "Pthread Signal ");
		}
	}

	return;
}

/* It will do wait () if no alarm in list or do timed wait if alarm is in list */
void *alarm_thread(void *arg) 
{
	alarm_t *alarm;
	struct timespec timeout;
	time_t now;
	int status, expired;

	status = pthread_mutex_lock(&alarm_mutex);
	if (status != 0) {
		err_abort(status, "Mutex Lock");
	}

	while(1) {
		/* wait */
		current_alarm = 0;
		while (alarm_list == NULL) {
			status = pthread_cond_wait(&alarm_cond, &alarm_mutex);
			if (status != 0) {
				err_abort(status, "Cond Wait ");
			}
		}
		/* We came out of wait */
		alarm = alarm_list;
		now  = time(NULL);

		/* Not yet expired */
		if (alarm->time > now) {
			printf("Waiting Alarm :%d %s ", alarm->time, alarm->msg);
			timeout.tv_sec = alarm->time;
			timeout.tv_nsec = 0;
			current_alarm = alarm->time;
			while(current_alarm == alarm->time) {
				status = pthread_cond_timedwait(&alarm_cond, &alarm_mutex, &timeout);
				if (status == ETIMEDOUT) {
					expired = 1;
					break;
				} else if (status != 0) {
					err_abort(status, "Cond Timed Wait ");
				}
			}

			if (!expired) {
				alarm_insert(alarm);
			}
		} else {
			expired = 1;
		}
		if (expired) {
			printf("Alarm expired :%d and %s \n", alarm->time, alarm->msg);
			free(alarm);
		}
	}
	return NULL;
}


int main(int argc, char *argv[]) 
{
	int status;
	char line[128];
	alarm_t *alarm;
	pthread_t thread;
	
	status = pthread_create(&thread, NULL, alarm_thread, NULL);
	if (status != 0) {
		err_abort(status, "Thread create failed ");
	}

	while(1) {
		if ((fgets(line,sizeof(line),  stdin) == NULL)) {
			exit(0);
		} 
		if (strlen(line) < 2) {
			continue;
		}

		alarm  = malloc(sizeof(alarm_t));
		if (alarm != NULL) {
			alarm = (alarm_t *)alarm;
		} else {
			err_abort(status, "malloc failed");
		}

		if ((sscanf(line, "%d, %64[^\n]", alarm->seconds, alarm->msg) < 2)) {
				fprintf(stderr, "bad Command\n");
				free(alarm);
		} else {
			status = pthread_mutex_lock(&alarm_mutex);
			if (status != 0) {
				err_abort(status, "Mutex Lock ");
			}
			alarm->time = time(NULL)  + alarm->seconds;
			/* insert the alarm */
			alarm_insert(alarm);

			status = pthread_mutex_unlock(&alarm_mutex);

			if (status != 0 ) {
				err_abort(status, "Unlock Mutex ");
			}
		}
	}
	return 0;
}

