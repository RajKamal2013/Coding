#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "debug.h"
#include "common.h"

typedef struct slist {
	struct head_common_data *c_data;
	struct elmt *head;
	struct elmt *tail;
	struct elmt *mid;		/* For faster search */
} slist_t;

//slist_t *list_recycle_bin = NULL;

slist_t* slist_init(bool threadsafe, void (*free_func)(void *),
		    int (*compare_func)(void *, void *));
void slist_destroy(slist_t *list);
bool slist_is_empty(slist_t *list);
bool slist_is_empty_safe(slist_t *list);
void *slist_head(slist_t *list);
void *slist_tail(slist_t *list);
uint32_t slist_size(slist_t *list);
/* Insert APIs */
void slist_insert(slist_t *list, void *after, void *data);
void slist_push_front(slist_t *list, void *data);  /* insert at beginning */
void slist_push_back(slist_t *list, void *data);
/* Remove APIs */
void slist_remove(slist_t *list, void *data);
void* slist_pop_front(slist_t *list);  /* remove from front */
void* slist_pop_back(slist_t *list);   /* remove from back */
/* Search APIs */
bool elmt_exist(slist_t *list, void *data);
bool elmt_exist_safe(slist_t *list, void *data);
elmt_t *slist_search(slist_t *list, void *data);
elmt_t *slist_search_safe(slist_t *list, void *data);
/* Iter APIs */
void* list_iter_first(iter_cookie_t *cookie);
void* list_iter_next(iter_cookie_t *cookie);
//void slist_display(slist_t *list);
