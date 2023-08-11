/*
 * External Sorting ->
 * 		1. Array1, Array2, Array3, Array4, Array5 --> Each with 50 element and sorted
 * 		2. Cache -> 5 array of 10 element each to pick for sorting.
 * 		3. Heap  -> heap of 50 element and it will merge the elements of array1,..., array5
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "debug.h"
#include "sort.h"


#define HEAPCACHESIZE 10
#define BATCHCOUNT 5
#define BATCHSIZE 50
#define TOTALSIZE 250

/* Heap Data */
typedef struct heapElmt_s {
	int data;
	int idx; 		/* array to which element belongs */
} heapElmt_t;

/* Cache to hold the data for heap sort */
typedef struct heapCache_s {
	TAILQ Q[HEAPCACHESIZE];
	int cacheId;
	pthread_mutex_t mutex;
	int element_used;
} heapCache_t;

/* TAILQ */


/*
 * Payload Data -> Shared by 2 threads
 * 	1. Producer Thread -> Creating Cache
 * 	2. Consumer Thread -> Take data from cache and sort
 */
typedef struct payload_s {
	/* Synchronization Elements */
	int ready;
	int done;
	pthread_t cache_tid;
	pthread_t heap_tid;
	pthread_mutex_t mutex;
	pthtead_cond_t cv;
	/* Circular Array */
	heapCache_t cache[BATCHCOUNT];
	int cache_index[BATCHCOUNT];
	/* Heap */
	heapElm_t heap[BATCHSIZE];
	/* This will be dumped to file */
	int output[HEAPCACHESIZE];
} payload_t;


void get_data_from_file_to_cache(heapCache_t *cache)
{


}

void * do_update_cache(void *arg)
{
}

void do_generate_heap_and_cache(void *arg)
{
	int status;
	payload_t *data = NULL;

	if (arg == NULL) {
		arg = (payload_t *)calloc(1, sizeof(payload_t));
	}

	data = (payload_t *) arg;

	data->ready = 0;
	data->done = 0;

	status = pthread_mutex_init (&data->mutex, NULL);
	if (status != 0) {
		err_abort(status, "Mutex Initialization Failed");
	}

	status = pthead_cond_init(&data->cv, NULL);
	if (status != 0) {
		err_abort(status, "CV Initialization Failed");
	}

	status = pthread_create(&data->heap_tid, NULL, do_heap_sort, (void *)data);
	if (status != 0) {
		err_abort(status, "Thread creation failed for heap ");
	}

	status = pthread_create(&data->cache_tid, NULL, do_update_cache, (void *)data);
	if (status != 0) {
		err_abort(status, "Thread creation failed for heap ");
	}

	status = pthread_join(data->cache_tid, NULL);
	if (status != 0) {
		err_abort(status, "Thread Join failed  for cache Thread");
	}

	status = pthread_join(data->heap_tid, NULL);
	if (status != 0) {
		err_abort(status, "Thread join failed for heap thread");
	}

	status = pthread_mutex_destroy(&data->mutex);
	if (status != 0) {
		err_abort(status, "Mutex destroy failed ");
	}

	status = pthread_cond_destroy(&data->cv);
	if (status != 0) {
		err_abort(status, "CV destroy failed");
	}
	free(data);
}



