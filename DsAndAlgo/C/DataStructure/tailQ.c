#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"
#include <pthread.h>
#include <unistd.h>
#include "tailQ.h"
#include <stdint.h>
#include <assert.h>

/* ----------------------- Queue1 Generic Implementation ----------------------*/
int elmt_lock(pthread_mutex_t *lock)
{
	int status = 0;
	status = pthread_mutex_lock(lock);
	if (status != 0) {
		err_out("Not able to lock mutex ");
	}
	return status;
}

int elmt_unlock(pthread_mutex_t *lock)
{
	int status = 0;
	status = pthread_mutex_unlock(lock);
	if (status != 0) {
		err_out("Not able to unlock mutex ");
	}
	return status;
}

void add_ref(void *data, bool safe)
{
	elmt_common_data_t *c_data = (elmt_common_data_t *)data;
	assert(c_data->valid);
	if (!safe) {
		if (elmt_lock(&c_data->lock)) {
			assert(0);
		}
	}
	c_data->ref++;
	if (!safe) {
		if (elmt_unlock(&c_data->lock)) {
			assert(0);
		}
	}
}

void dec_ref(void *data, bool safe)
{
	elmt_common_data_t *c_data = (elmt_common_data_t *)data;
	if (!safe) {
		if (elmt_lock(&c_data->lock)) {
			assert(0);
		}
	}
	c_data->ref--;
	if (c_data->ref == 0) {
		if (!safe) {
			if (elmt_unlock(&c_data->lock)) {
				assert(0);
			}
		}
		/* we shall call this deletion via garbage threads */
		free_elmt_common_data(&c_data);
		free_queue1_elmt(data);
	} else {
		if (!safe) {
			if (elmt_unlock(&c_data->lock)) {
				assert(0);
			}
		}
	}
}

/* This initializes the common data */
elmt_common_data_t*
init_elmt_common_data(void *data)
{
	if (data == NULL) {
		assert(0);
		return NULL;
	}
	elmt_common_data_t *c_data = (elmt_common_data_t *)data;
	int status;
	c_data = (elmt_common_data_t *)malloc(sizeof(elmt_common_data_t));
	c_data->ref = 1;
	c_data->data_gen = 1;
	c_data->valid = true;
	c_data->container = data;
	status = pthread_mutex_init(&c_data->lock, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed for Queue");
	}
	return c_data;
}

/* Frees the common data */
void free_elmt_common_data(void *data)
{
	if (data == NULL) {
		err_out("Already common data is freed ");
		return;
	}
	elmt_common_data_t *c_data = data;
	assert(c_data->ref == 0);
	assert(c_data->valid == false);
	assert(c_data->data_gen > 0);
	c_data->container = NULL;
	int status = pthread_mutex_destroy(&c_data->lock);
	if (status != 0) {
		err_abort(status, "Mutex Destroy failed");
	}
	free(c_data);
}

/* This initializes the common data */
head_common_data_t*
init_head_common_data(uint32_t capacity, uint32_t size, bool threadsafe)
{
	int status;
	head_common_data_t *c_data = NULL;

	c_data = (head_common_data_t *)malloc(sizeof(head_common_data_t));
	c_data->capacity = capacity;
	c_data->size = size;
	c_data->threadsafe = threadsafe;
	status = pthread_mutex_init(&c_data->lock, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed for Queue");
	}
	return c_data;
}

/* Frees the common data */
void free_head_common_data(void *data)
{
	int status;
	head_common_data_t *c_data = (head_common_data_t *)data;
	if (c_data == NULL) {
		err_out("Already common data is freed ");
		return;
	}
	assert(c_data->capacity == 0);
	assert(c_data->size == 0);
	status = pthread_mutex_destroy(&c_data->lock);
	if (status != 0) {
		err_abort(status, "Mutex Destroy failed");
	}
	free(c_data);
}

void free_queue1_elmt(void *data)
{
	queue1_elmt_t *elmt = data;
	assert(elmt);
	if (elmt->free_func) {
		elmt->free_func(elmt->data);
	}
	elmt->owner = NULL;
	free(elmt);
}

/* Initializes the Queue */
queue1_t* queue1_init(int capacity, bool threadsafe,
		void free_func(void *), int compare_func(void *, void *))
{
	queue1_t *Q = NULL;
	Q = (queue1_t *) malloc (sizeof(queue1_t));
	assert(Q != NULL);
	Q->c_data = init_head_common_data(capacity, 0, threadsafe);
	assert(Q->c_data);
	Q->head = NULL;
	Q->tail = NULL;
	Q->c_data->free_func = free_func;
	Q->c_data->compare_func = compare_func;
	return Q;
}

/* Destroy the Queue */
void queue1_destroy(queue1_t  *Q)
{
	assert(Q->c_data->size == 0);
	assert(Q->head == NULL);
	assert(Q->tail == NULL);
	free_head_common_data(Q);
	free(Q);
}

/* Check if Queue is full */
bool queue1_is_full(queue1_t *Q) 
{
	bool ret = false;
	assert(Q != NULL);
	head_common_data_t *c_data = Q->c_data;
	assert(c_data);
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		assert(0);
	}
	/* Capacity is -1 means Queue is infinite */
	if ((c_data->capacity != -1) && (c_data->capacity == c_data->size)) {
		ret = true;
	}
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		assert(0);
	}
	return ret;
}

/* Check if Queue is empty */
bool queue1_is_empty(queue1_t *Q)
{
	bool ret = false;
	head_common_data_t *c_data = Q->c_data;
	assert(c_data);
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		assert(0);
	}
	if (Q->head == NULL) {
		assert(c_data->size == 0);
		ret = true;
	}
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		assert(0);
	}
	return ret;
}

/* Give the top of the queue. Beter take ref after calling this API */ 
void* queue1_top(queue1_t *Q)
{
	void *data;
	head_common_data_t *c_data = Q->c_data;
	assert(c_data);
	if (queue1_is_empty(Q)) {
		return NULL;
	} 

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		assert(0);
	}
	data = Q->head->data;

	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		assert(0);
	}
	return (data);
}

/* What's the size of Queue */
uint32_t queue1_size(queue1_t *Q)
{
	uint32_t size;
	head_common_data_t *c_data = Q->c_data;
	assert(c_data);

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		assert(0);
	}
	size = c_data->size;
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		assert(0);
	}
	return (size);
}

/* Enqueue Function */
void queue1_enqueue(queue1_t *Q, void *data)
{
	assert(Q != NULL);
	head_common_data_t *c_hdata = Q->c_data;
	assert(c_hdata);
	assert(c_hdata->capacity != 0);
	if (c_hdata->threadsafe) {
		if (elmt_lock(&c_hdata->lock)) {
			assert(0);
		}
	}
	
	if ((c_hdata->capacity != -1) && (c_hdata->capacity == c_hdata->size)) {
		err_out("Queue is FULL ");
		if (c_hdata->threadsafe && elmt_unlock(&c_hdata->lock)) {
			assert(0);
			return;
		}
		return;
	}
	queue1_elmt_t *elmt = (queue1_elmt_t *)malloc(sizeof(queue1_elmt_t));
	elmt->c_data = init_elmt_common_data(elmt);
	assert(elmt->c_data);
	/* Common data to all my DS */
	elmt->owner = Q;
	elmt->data = data;
	elmt->free_func = c_hdata->free_func;
	elmt->compare_func = c_hdata->compare_func;
	elmt->next = NULL;
	
	if (Q->head == NULL) {
		assert(c_hdata->size == 0);
		Q->head = elmt;
		Q->tail = elmt;
	} else {
		assert(c_hdata->size > 0);
		Q->tail->next = elmt;
		Q->tail = elmt;
		Q->tail->next = Q->head;
	}
	if (c_hdata->size == 1) {
		Q->head->next = Q->tail;
	}
	c_hdata->size++;
	elmt->c_data->valid = true;
	if ((c_hdata->threadsafe) && elmt_unlock(&c_hdata->lock)) {
		assert(0);
	}
}
/* Dequeue Function */
void* queue1_dequeue(queue1_t *Q)
{
	if (queue1_is_empty(Q)) {
		err_out("Queue is empty ");
		assert(Q->c_data->size == 0);
		return NULL;
	}
	head_common_data_t *c_hdata = (head_common_data_t*)Q->c_data; 
	assert(c_hdata);
	if (c_hdata->threadsafe && elmt_lock(&c_hdata->lock)) {
		assert(0);
	}
	queue1_elmt_t *elmt = NULL;
	elmt = Q->head;
	assert(elmt);
	elmt_common_data_t *c_data = elmt->c_data;
	assert(c_data);
	if (elmt_lock(&c_data->lock)) {
		assert(0);
	}
	void *data = elmt->data;
	if (Q->head == Q->tail) {
		assert(c_hdata->size == 1);
		Q->head = NULL;
		Q->tail = NULL;
	} else {
		Q->head = Q->head->next;
	}
	c_data->valid = false;
	elmt->next = NULL;
	if (elmt_unlock(&c_data->lock)) {
		assert(0);
	}
	dec_ref(elmt, true);
	c_hdata->size--;
	if (c_hdata->threadsafe && elmt_unlock(&c_hdata->lock)) {
		assert(0);
	}
	/* data can be null if ref is not taken by the caller */
	return data;
}



/* For each Like API for queue */

/* Initializes the cookie for iteration */
/*
void queue1_iter_init(queue1_itr_cookie_t **cookie) 
{
	if (*cookie == NULL) {
		*cookie = (queue1_itr_cookie_t *)malloc(sizeof(queue1_itr_cookie_t));
	}
}
*/
/* Start the iteration  */
/*
void* queue1_iter_first(queue1_t *Q, queue1_itr_cookie_t *cookie)
{
	if (Q == NULL) {
		err_out("Queue is empty ");
		return NULL;
	}
	if (cookie == NULL) {
		err_out("Cookie not initialized");
		return NULL;
	} 
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_lock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display :");
		}
	}
	cookie->Q = Q;
	cookie->curr = NULL;
	if (Q->head) {
		cookie->curr = Q->head;
		cookie->curr_data_gen = Q->head->data_gen;
		add_ref(cookie->curr);
	}
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_unlock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex unLock failed for display :");
		}
	}
	return (void*)cookie->curr;
}
*/
/* Get the next in iteration */
/*
void *queue1_iter_next(queue1_itr_cookie_t *cookie)
	queue1_elmt_t *next;
	if (cookie == NULL) {
		err_out("Cookie not available");
		return NULL;
	} 
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_lock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display :");
		}
	}
	if (cookie->curr) {
		next = cookie->curr->next;
		dec_ref(cookie->curr);
		cookie->curr = next;
		if (cookie->curr) {
			add_ref(cookie->curr);
			cookie->curr->curr_data_gen = cookie>curr->data_gen;
		}
	} else {
		err_out("Current is freed");
		return NULL;
	}
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_lock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display :");
		}
	}
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_unlock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex UnLock failed for display :");
		}
	}
	return (void*)cookie->curr;
}
*/
/* Destroys the cookie after iteration is over */
/*
void *queue1_iter_done(queue1_itr_cookie_t *cookie)
{
	if (cookie == NULL) {
		err_out("Cookie not available");
		return NULL;
	} 
	if (Q->threadsafe) {
		int status;
		status = pthread_mutex_lock(&Q->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display :");
		}
	}
	if (cookie->curr) {
		dec_ref(cookie->curr);
		cookie->curr = NULL;
	}
	free(cookie);
}
*/
/* ----------------------- Queue1 Linux Container Implementation ----------------------*/
/*
typedef struct Queue2_t {
	struct Queue2_t *head;
	struct Queue2_t *tail;
	uint32_t size; *//* -1 for infinite size 
} Queue2_t;
*/



	
