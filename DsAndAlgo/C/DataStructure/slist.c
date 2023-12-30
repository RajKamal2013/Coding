#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "debug.h"
#include "slist.h"

//slist_t *list_recycle_bin = NULL;

slist_t* slist_init(bool threadsafe, void (*free_func)(void *),
		    int (*compare_func)(void *, void *))
{
	slist_t *list = NULL;
	list = (slist_t *)malloc(sizeof(slist_t));
	assert(list);
	list->c_data = init_head_common_data(-1, 0, threadsafe);
	assert(list->c_data);
	list->c_data->free_func = free_func;
	list->c_data->compare_func = compare_func;
	list->head = NULL;
	list->tail = NULL;
	list->mid = NULL;
	return list;
}

void slist_destroy(slist_t *list)
{
	if (list == NULL) {
		err_out("slist already freed ");
		return;
	} 
	assert(list->c_data);
	assert(list->c_data->size == 0);
	assert(list->head == NULL);
	assert(list->tail == NULL);
	assert(list->mid == NULL);
	free_head_common_data(list);
	free(list);
}

bool slist_is_empty(slist_t *list)
{
	bool ret = false;
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock in threadsafe list");
		assert(0);
	}
	if (list->head == NULL) {
		assert(list->c_data->size == 0);
		ret = true;
	}
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to release the lock");
		assert(0);
	}
	return ret;
}

bool slist_is_empty_safe(slist_t *list)
{
	bool ret = false;
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	if (list->head == NULL) {
		assert(c_data->size == 0);
		ret = true;
	}
	return ret;
}


void *slist_head(slist_t *list)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	void *data = NULL;

	if (slist_is_empty(list)) {
		data = NULL;
	} else {
		if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
			err_out("Not able to take the lock");
			assert(0);
		}
		if (list->head->c_data->valid) {
			data = (void *)list->head->data;
		} else {
			err_out("Head is not valid");
			data = NULL;
		}
		if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
			err_out("Not able to release the lock");
			assert(0);
		}
	}
	return data;
}

void *slist_tail(slist_t *list)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	void *data = NULL;
	if (slist_is_empty(list)) {
		data = NULL;
	} else {
		if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
			err_out("Not able to take the lock");
			assert(0);
		}
		assert(list->tail);
		if(list->tail->c_data->valid) {
			data = list->tail->data;
		} else {
			err_out("Tail is not valid ");
			data = NULL;
		}
		if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
			err_out("Not able to release the lock");
			assert(0);
		}
	}
	return data;
}

uint32_t slist_size(slist_t *list)
{
	assert(list);
	assert(list->c_data);
	uint32_t size;
	head_common_data_t *c_data = list->c_data;

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take the lock");
		assert(0);
	}
	size =  list->c_data->size;
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to release the lock");
		assert(0);
	}
	return size;
}

void slist_push_front(slist_t *list, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = init_elmt(list, data);
	assert(elmt);
	assert(elmt->c_data);
	elmt->free_func = list->c_data->free_func;
	elmt->compare_func = list->c_data->compare_func;

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return;
	}

	if (slist_is_empty_safe(list)) {
		assert(list->c_data->size == 0);
		elmt->next = NULL;
		list->head = elmt;
		list->tail = elmt;
	} else {
		assert(list->c_data->size > 0);
		elmt->next = list->head;
		list->head = elmt;
	}
	list->c_data->size++;

}

void slist_push_back(slist_t *list, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = init_elmt(list, data);
	assert(elmt);
	assert(elmt->c_data);
	elmt->free_func = c_data->free_func;
	elmt->compare_func = c_data->compare_func;

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock");
		assert(0);
		return;
	}
	
	if (slist_is_empty_safe(list)) {
		assert(c_data->size == 0);
		elmt->next = NULL;
		list->head = elmt;
		list->tail = elmt;
	} else {
		assert(list->tail);
		assert(c_data->size > 0 );
		list->tail->next = elmt;
		list->tail = elmt;
	}
	
	c_data->size++;
}

elmt_t* slist_search(slist_t *list, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = NULL;
	int ret = -1;
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return NULL;
	} 

	if (slist_is_empty_safe(list)) {
		assert(c_data->size == 0);
		elmt = NULL;
	} else {
		assert(list->head);
		assert(list->tail);
		assert(c_data->size > 0);
		elmt_t *curr = list->head;
		int *d1, *d2;
		d1 = NULL;
		d2 = NULL;
		while(curr != NULL) {
			if (curr->compare_func) {
				ret = curr->compare_func(curr->data, data);
			} else {
				d1 = (int *)data;
				d2 = (int *)curr->data;
				if (*d1 == *d2) {
					ret = 0;
				}
			}
			if (ret == 0) {
				elmt = curr;
				break;
			} else {
				curr = curr->next;
			}
		}
	} 

	if(c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to release the lock ");
		assert(0);
		return elmt;
	}
	return elmt;
}

elmt_t *slist_search_safe(slist_t *list, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = NULL;

	if (slist_is_empty_safe(list)) {
		assert(c_data->size == 0);
		elmt = NULL;
	} else {
		assert(list->head);
		assert(list->tail);
		assert(c_data->size > 0);
		elmt_t *curr = list->head;
		int *d1, *d2;
		d1 = NULL;
		d2 = NULL;
		int ret = -1;
		while(curr != NULL) {
			if (curr->compare_func) {
				ret = curr->compare_func(curr->data, data);
			} else {
				d1 = (int *)data;
				d2 = (int *)curr->data;
				if (*d1 == *d2) {
					ret = 0;
				}
			}
			if (ret == 0) {
				elmt = curr;
				break;
			} else {
				curr = curr->next;
			}
		}
	} 
	return elmt;
}

void slist_insert(slist_t *list, void *after, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	assert(c_data->size > 0);
	assert(list->head);
	assert(list->tail);
	assert(after);

	elmt_t *curr = NULL;

	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return;
	}
	curr = slist_search_safe(list, after);
	if (curr != NULL) {
		elmt_t *elmt = init_elmt(list, data);
		assert(elmt);
		assert(elmt->c_data);
		elmt->free_func = c_data->free_func;
		elmt->compare_func = c_data->compare_func;
		elmt->next = curr->next;
		curr->next = elmt;
	} else {
		err_out("Not able to add in list as data doesn't exist");
	}
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return;
	}
	return;
}

void slist_remove(slist_t *list, void *data)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	assert(list->head);
	assert(list->tail);
	elmt_t *curr = list->head;
	elmt_t *prev = NULL;
	int ret = -1;
	
	if (slist_is_empty(list)) {
		err_out("List is empty ");
		assert(0);
		return;
	}
	
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return;
	}

	while(curr) {
		if (curr->compare_func) {
			ret = curr->compare_func(curr->data, data);
		} else {
			int *d1, *d2;
			d1 = (int *)curr->data;
			d2 = (int *)data;
			if (*d1 == *d2) {
				ret = 0;
			}
		} 
		if (ret == 0) {
			if (prev == NULL) { /* head case */
				list->head = curr->next;
				curr->next = NULL;
			} else {
				prev->next = curr->next;
				curr->next = NULL;
			}
		} else {
			prev = curr;
		}
	}

	if (curr == NULL) {
		err_out("Element not found");
	} else {
		/* do in garbsae thread */
		free_elmt_common_data(curr);
		free_elmt(curr);
	}
	list->c_data->size--;

	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return;
	}
}

void *slist_pop_front(slist_t *list)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = NULL;
	void *data = NULL;
	if (slist_is_empty(list)) {
		err_out("List is empty ");
		return data;
	}
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return data;
	}

	elmt = list->head;
	list->head = list->head->next;
	elmt->next = NULL;
	data = elmt->data;
	elmt->data = NULL;
	dec_ref_without_free(elmt, true);
	free_elmt_common_data(elmt);
	free_elmt_without_data(elmt);
	c_data->size--;
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return data;
	}
	return data;
}

void* slist_pop_back(slist_t *list)
{
	assert(list);
	assert(list->c_data);
	head_common_data_t *c_data = list->c_data;
	elmt_t *elmt = NULL;
	void *data = NULL;
	if (slist_is_empty(list)) {
		err_out("List is free");
		return data;
	}
	if (c_data->threadsafe && elmt_lock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return data;
	}
	assert(list->head);
	elmt_t *curr = list->head;
	if (list->head == list->tail) {
		assert(c_data->size == 1);
		elmt = list->tail;
		list->head = NULL;
		list->tail = NULL;
	} else {
		while(curr->next != list->tail) {
			curr = curr->next;
		}
		elmt = list->tail;
		curr->next= NULL;
		list->tail = curr;
	}
	data = elmt->data;
	elmt->data = NULL;
	dec_ref_without_free(elmt, true);
	free_elmt_common_data(elmt);
	free_elmt_without_data(elmt);
	c_data->size--;
	if (c_data->threadsafe && elmt_unlock(&c_data->lock)) {
		err_out("Not able to take lock ");
		assert(0);
		return data;
	}
	return data;
}

bool elmt_exist(slist_t *list, void *data)
{
	if (list == NULL) {
		err_out("List is empty ");
		assert(list);
		return false;
	}
	elmt_t *elmt = slist_search(list, data);
	if (elmt != NULL) {
		return true;
	} else {
		return false;
	}
}
bool elmt_exist_safe(slist_t *list, void *data)
{
	if (list == NULL) {
		err_out("List is empty");
		assert(list);
		return false;
	}
	elmt_t *elmt = slist_search_safe(list, data);
	if (elmt != NULL) {
		return true;
	} else {
		return false;
	}
}
void slist_display(slist_t *list);
void slist_reverse(slist_t *list);
void slist_sort(slist_t *list);
/* Iter APIs */
