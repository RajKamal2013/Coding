#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "debug.h"
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include "common.h"

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
	elmt_t *elmt = (elmt_t *)data;
	assert(elmt);
	elmt_common_data_t *c_data = elmt->c_data;
	assert(c_data);
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
	elmt_t *elmt = (elmt_t *)data;
	assert(elmt);
	elmt_common_data_t *c_data = elmt->c_data;
	assert(c_data);
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
		free_elmt(data);
	} else {
		if (!safe) {
			if (elmt_unlock(&c_data->lock)) {
				assert(0);
			}
		}
	}
}

void dec_ref_without_free(void *data, bool safe)
{
	elmt_t *elmt = (elmt_t *)data;
	assert(elmt);
	elmt_common_data_t *c_data = elmt->c_data;
	assert(c_data);
	if (!safe) {
		if (elmt_lock(&c_data->lock)) {
			assert(0);
		}
	}
	assert(c_data->ref == 1);
	c_data->ref--;
	c_data->valid = false;
	assert(c_data->ref == 0);
	if (!safe) {
		if (elmt_unlock(&c_data->lock)) {
			assert(0);
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
	elmt_t *elmt = (elmt_t *)data;
	elmt_common_data_t *c_data = elmt->c_data;
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
	elmt_t *elmt = (elmt_t *)data;
	assert(elmt->c_data);
	elmt_common_data_t *c_data = elmt->c_data;
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

/* responsibility of caller to add the free func and compare func */
elmt_t *init_elmt(void *owner, void *data)
{
	elmt_t *elmt = (elmt_t *)malloc(sizeof(elmt_t));
	assert(elmt);
	elmt->c_data = init_elmt_common_data(elmt);
	assert(elmt->c_data);
	elmt->data = data;
	elmt->owner = owner;
	elmt->next = NULL;
	elmt->free_func = NULL;
	elmt->compare_func = NULL;
	return elmt;
}

void free_elmt(void *data)
{
	elmt_t *elmt = data;
	assert(elmt);
	if (elmt->free_func) {
		elmt->free_func(elmt->data);
	}
	elmt->owner = NULL;
	free(elmt);
}

void free_elmt_without_data(void *data)
{
	elmt_t *elmt = data;
	assert(elmt);
	assert(elmt->data == NULL);
	elmt->owner = NULL;
	free(elmt);
}

iter_cookie_t* iter_init(void *container, char *type, uint32_t flags, void (*display_func)(void *data)) 
{
	iter_cookie_t *cookie = NULL;
	assert(container);
	cookie = (iter_cookie_t *)malloc(sizeof(iter_cookie_t));
	cookie->container = container;
	cookie->curr = NULL;
	cookie->type = type;
	cookie->curr_datagen = -1;
	cookie->flags = flags;
	cookie->display_func = display_func;
	cookie->ref_taken = false;
	return cookie;
}

void iter_done(iter_cookie_t *cookie)
{
	assert(cookie);
	assert(cookie->curr);
	assert(cookie->curr->c_data);
	if (cookie->flags && ITER_FLAG_LOCK) {
		if (!elmt_unlock(&cookie->curr->c_data->lock)) {
			err_out("Not able to release the lock ");
			assert(0);
			return;
		}
	}
	if (cookie->ref_taken) {
		dec_ref(cookie->curr, false);
		cookie->ref_taken = false;	
	}

	cookie->container = NULL;
	cookie->curr = NULL;
	free(cookie);
}
