#include <pthread.h>
#include "debug.h"

/* Some one will call pipe_send() that will signal next stage thread function */


/* Stage -> Individual pipe that alltogether makes pipeline */
typedef struct stage_tag {
	pthread_mutex_t mutex;	/* Mutex */
	pthread_cond_t avail;	/* Signal when data is available to pass to next stage <Now consume> */
	pthread_cond_t ready;	/* Signal when data is sent to next stage, so that it produces for next */
	int data_ready;		/* Set when data is ready <Just produced> */
	long data;		/* Payload to be sent across the stage */
	pthread_t thread;	/* Each stage is associated with a thread */
	struct stage_tag *next;	/* pointer to next stage */
} stage_t;


/* This structure is whole pipeline */
typedef struct pipe_tag {
	pthread_mutex_t mutex;	/* Pipeline mutex */
	stage_t *head;		/* First stage of pipeline */
	stage_t *tail;		/* Last stage of pipeline */
	int stages;		/* Number of stages in a pipeline */
	int active;		/* Is pipeline completed */
} pipe_t;

/*
 * API Send the data to next stage and signal stage to produce next
 * Pipeline will be kicked off by this function.
 */
int pipe_send(stage_t *stage, long data)
{
	int status;

	status = pthread_mutex_lock(&stage->mutex);
	if (status != 0) {
		return status;
	}

	/* Until the thread function has not consumed data, wait */
	while(stage->data_ready) {
		/* wait until stage has not consumed */
		status = pthread_cond_wait(&stage->ready, &stage->mutex);
		if (status != 0) {
			pthread_mutex_unlock(&stage->mutex);
			return status;
		}
	}

	/* We are sure that data is consumed and now its time to produce the data */
	stage->data = data;
	stage->data_ready = 1;

	/* Signal Thread function so that it can send data to next stage */
	status = pthread_cond_signal(&stage->avail);
	if (status != 0) {
		pthread_mutex_unlock(&stage->mutex);
		return status;
	}

	status = pthread_mutex_unlock(&stage->mutex);
	return status;
}

/* Thread function, modify the data and send to next stage */
void *pipe_stage(void *arg)
{
	stage_t *stage = (stage_t *)arg;
	stage_t *next_stage = stage->next;
	int status;

	status = pthread_mutex_lock(&stage->mutex);
	if (status != 0) {
		err_abort(status, "Lock Pipe Stage ");
	}

	while(1) {
		/* wait till data is not consumed */
		while(stage->data_ready != 1) {
			status = pthread_cond_wait(&stage->avail, &stage->mutex);
			if (status != 0) {
				err_abort(status, "Wait for previous stage ");
			}
		}
		/* produce and sent to next stage */
		pipe_send(next_stage, stage->data + 1 );
		/* unset data not ready until its not produced */ 
		stage->data_ready = 0;
		/* signal to produce data */
		status = pthread_cond_signal(&stage->ready);
		if (status != 0) {
			err_abort(status, "Wake next stage ");
		}
	}
	/* pthread_cond_signal() unlocks the mutex, so its cool */
}

/* Set up pipeline and associated stages */
int pipe_create(pipe_t *pipe, int stages)
{
	int pipe_index;
	stage_t **link, *stage, *next_stage;
	int pipe_index = 0;
	int status = 0;

	/* Set up the PipeLine */
	if (pipe == NULL) {
		pipe = (pipe_t *)malloc(sizeof(pipe_t);
	}
	pipe->stages = stages;
	status = pthread_mutex_init(&pipe->mutex, NULL);
	if (status != 0) {
		err_abort(status, "pthread_mutex_init() failed ");
	}
	pipe->active = 0;

	pipe->head = NULL;
	pipe->tail = NULL;

	/* create the stages of pipeline */
	link = &pipe->head;
	for (pipe_index = 0; pipe_index <= stages; pipe_index++) {
		next_stage = (stage_t *)malloc(sizeof(stage_t));
		if (next_stage == NULL) {
			errno_abort("Malloc failed for stage_t ");
		}

		status = pthread_mutex_init(&new_stage->mutex, NULL);
		if (status != 0) {
			err_abort(status, "pthread_mutex_init() failed for stage mutex");
		}

		status = pthread_cond_init(&new_stage->avail, NULL);
		if (status != 0) {
			err_abort(status, "pthread_cond_init() failed for stage's avail cv");
		}

		status = pthread_cond_init(&new_stage->ready, NULL);
		if (status != 0) {
			err_abort(status, "pthread_cond_init() failed for stage's ready cv");
		}

		new_stage->data_ready = 0;
		*link = new_stage;
		link = &new_stage->next;
	}

	*link = (stage_t *)NULL;
	pipe->tail = new_stage;

	/* Now creata a thread and associate it with each stage of pipeline */
	for (stage = pipe->head; stage->next != NULL; stage = stage->next) {
		status = pthread_create(&stage->thread, NULL, pipe_stage, (void *)stage);
		if (status != 0) {
			err_abort(status, "pthread_create() failed for the stage thread ");
		}
	}
	return 0;
}

/* Interface to start the pipeline */
int pipe_start(pipe_t *pipe, long value)
{
	int status;

	status = pthread_mutex_lock(&pipe->mutex);
	if (status != 0) {
		err_abort(status, "pthread_mutex_lock() for pipe->mutex");
	}
	pipe->active++;
	status = pthread_mutex_unlock(&pipe->mutex);
	if (status != 0) {
		err_abort(status, "pthread_mutex_unlock() for pipe->mutex");
	}
	/* start the pipeline -> YO !!*/
	pipe_send(pipe->head, value);

	return 0;
}

/* Collect the result */
int pipe_result(pipe_t *pipe, long *result)
{
	stage_t *tail = pipe->tail;
	long value;
	int empty = 0;
	int status;

	status = pthread_mutex_lock(&pipe->mutex);
	if (status != 0) {
		err_abort(status, "pthread_mutex_lock() failed for pipe->mutex");
	}
	if (pipe->active <= 0) {
		empty = 1;
	} else {
		pipe->active--;
	}

	status = pthread_mutex_unlock(&pipe->mutex);
	if (status != 0) {
		err_abort(status, "pthread_mutex_unlock() failed for pipe->mutex");
	}
	if (empty) {
		return 0;
	}
	pthread_mutex_lock(&tail->mutex);
	while(!tail->data_ready) {
		pthread_cond_wait(&tail->avail, &tail->mutex);
	}

	*result = tail->data;
	tail->data_ready = 0;
	pthread_cond_signal(&tail->ready);
	pthread_mutex_unlock(&tail->mutex);
	return 1;
}

int main(int argc, char *argv[])
{
	pipe_t mypipe;
	long value, result;
	int status;

	pipe_create(&mypipe, 10);

	prope_start(&mypipe, 1);

	while(1) {
		status = pipe_result(&mypipe, &result);
		if (status) {
			printf("Value after Pipeline %d \n", result);
			break;
		}
	}
	return 0;
}

