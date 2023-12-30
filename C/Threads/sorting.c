#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "debug.h"


/* Thread 1 --> Produce  and signal to Thread  2 */
/* Thread 1 will be started by user program */

/* Thread 1 -> Produce array and sent to threads */
/* Thread 2 -> It will sort the array => Merge Sort */
/* Threed 3 -> It will sort the array => HeapSort */
/* Thread 4 -> It will sort the array => Quick Sort */

/* Thread 5 -> It will print the array */

/*--------------------------- Structures -------------------------------------->*/
typedef struct data_s {
	int *arr;		/* Array to Sort */
	int size;		/* Size of the Heap */
	int length;
	long time;		/* Time took to sort the array */
	pthread_t tid;
	pthread_mutex_t mutex;
	pthread_cond_t cv;
	int ready;
	int done;
} data_t;

typedef struct threadPayload_s {
	data_t *data;
	int ready;
	pthread_mutex_t mutex;
	pthread_cond_t cv;
	pthread_t sortThread;
	pthread_t displayThread;
	int done;
	char *type;
} threadPayload_t;

void print_array(data_t *data )
{
	int *arr = data->arr;
	int i = 0;
	printf("\n");
	for (i = 0; i < data->length;  i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	sleep(1);
}

/*<-------------------------------- APIs ------------------------------------------>*/

void swap (int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void *array_generator(void *arg)
{
	data_t *data = (data_t *)arg;
	int i = 0;
	int status;

	while (1) {
		status = pthread_mutex_lock(&data->mutex);
		if (status != 0) {
			err_abort(status, "Mutex lock failed for data ");
		}

		if (data->done) {
		       status = pthread_mutex_unlock(&data->mutex);
		       if (status != 0) {
		 		err_abort(status, "Mutex Unlock failed for data ");
			}
		       break;
		}

		while(data->ready) {
			status = pthread_cond_wait(&data->cv, &data->mutex);
			if (status != 0) {
				err_abort(status, "CV wait failed ");
			}
		}

		for (i = 0; i< data->length; i++) {
			data->arr[i]= rand() % 1000;
		}

		status = pthread_cond_signal(&data->cv);
		if (status != 0) {
			err_abort(status, "CV signal failed for data ");
		}
		data->ready = 1;
		data->done = 1;
		status = pthread_mutex_unlock(&data->mutex);
		if (status != 0) {
			err_abort(status, "mutex unlock failed ");
		}
		sleep(1);
	}
	return NULL;
}

void do_generate_array(void *arg)
{
	int status;
	data_t *data = (data_t *)arg;
	data->ready = 0;
	data->done = 0;

	status = pthread_mutex_init(&data->mutex, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed");
	}

	status = pthread_cond_init(&data->cv, NULL);
	if (status != 0 ) {
		err_abort(status, "CV Failed");
	}

	status = pthread_create(&data->tid, NULL, array_generator, (void *)data);
	if (status != 0 ) {
		err_abort(status, "Not able to create array generator thread ");
	}

	status  = pthread_mutex_lock(&data->mutex);
	if (status != 0)  {
		err_abort(status, "Not able to lock mutex ");
	}

	while(data->ready == 0) {
		status = pthread_cond_wait(&data->cv, &data->mutex);
		if (status != 0) {
			err_abort(status, "CV wait failed");
		}
	}

	sleep(1);
	printf("<-----------------Input Array --------------->\n");
	print_array(data);
	status = pthread_cond_signal(&data->cv);
	if (status != 0) {
		err_abort(status, "CV signal failed");
	}

	status = pthread_mutex_unlock(&data->mutex);
	if (status != 0 ) {
		err_abort(status, "Mutex unlock failed for data ");
	}

	status = pthread_join(data->tid, NULL);
	if (status != 0) {
		err_abort(status, "Not Able to join the array generator thread\n");
	}

	status = pthread_mutex_destroy(&data->mutex);
	if (status != 0) {
		err_abort(status, "Pthread_mutex_destroy Failed for data");
	}
	status = pthread_cond_destroy(&data->cv);
	if (status != 0) {
		err_abort(status, "Pthread_cv_destroy Failed for data");
	}
}

void *display_thread_func(void *arg)
{
	int status;
	threadPayload_t *payload = (threadPayload_t *)arg;

	while(1) {
		status = pthread_mutex_lock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display" );
		}
		if (payload->done == 1) {
			status = pthread_mutex_unlock(&payload->mutex);
			if (status != 0) {
				err_abort(status, "Mutex unlock failed for display");
			}
			break;
		}
		while (payload->ready != 1) {
			status = pthread_cond_wait(&payload->cv, &payload->mutex);
			if (status != 0) {
				pthread_mutex_unlock(&payload->mutex);
				err_abort(status, "CV wait failed for display ");
			}
		}

		printf("\n<-----------------Sorted Data by %s---------------------->\n", payload->type);
		print_array(payload->data);

		payload->ready = 0;
		payload->done = 1;
		status = pthread_cond_signal(&payload->cv);
		if(status) {
			err_abort(status, "CV signal failed for display thread:");
		}
		status = pthread_mutex_unlock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex unlock failed for display :");
		}
		/* sleep for 1 seconds */
		sleep(5);
	}
//	printf("Completed the Display Thread for %s \n", payload->type);
	return NULL;
}

/*--------------------------- Heap Sort --------------------------------*/

void max_heapify(data_t *data , int index)
{
	int *arr = data->arr;
	int heapsize = data->size;
	int left = 2 *index + 1;
	int right = 2 *index + 2;
	int largest = 0;

	if ((left < heapsize) && (arr[left] >= arr[index])) {
		largest = left;
	} else {
		largest = index;
	}

	if ((right < heapsize) && (arr[right] >= arr[largest])) {
		largest = right;
	}

	if (largest != index) {
		swap(data->arr, largest, index);
		max_heapify(data, largest);
	}
}

void build_max_heap(data_t *data)
{
	int heapsize = data->size;
	int index = 0;
	for (index = heapsize/2; index >= 0; index--) {
		max_heapify(data, index);
	}
}

void heap_sort(data_t *data)
{
	int *arr = data->arr;
	int heapsize = data->size;
	int index = 0;

	build_max_heap(data);

	for (index = heapsize - 1; index >= 1; index--) {
	       swap (arr, index, 0);
	       data->size = data->size - 1;
	       max_heapify(data, 0);
	 }
}

void *heap_sort_thread_func(void *arg)
{
	threadPayload_t *payload = (threadPayload_t *)arg;
	int status;
	while(1) {
		status = pthread_mutex_lock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex Lock failed for display :");
		}
		if (payload->done) {
			status = pthread_mutex_unlock(&payload->mutex);
			if (status != 0) {
				err_abort(status, "Mutex unlock failed for heapsort :");
			}
			break;
		}

		while(payload->ready) {
			status = pthread_cond_wait(&payload->cv, &payload->mutex);
			if (status != 0) {
				err_abort(status, "CV wait failed for display :");
			}
		}

		heap_sort(payload->data);
		payload->ready = 1;
		status = pthread_cond_signal(&payload->cv);
		if (status != 0) {
			err_abort(status, "CV Signal failed for heapsort");
		}
		status = pthread_mutex_unlock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex unlock failed for heapsort :");
		}
		/* sleep for 1 seconds */
		sleep(5);
	}
//	printf("Completed HeapSort Thread\n");
	return NULL;

}

void do_heap_sort(threadPayload_t *heapThreadPayload, data_t *data)
{
	int status;
	if (heapThreadPayload == NULL) {
		heapThreadPayload = (threadPayload_t *)calloc(1, sizeof(threadPayload_t ));
	}
	heapThreadPayload->ready = 0;
	heapThreadPayload->type = "HeapSort";
	heapThreadPayload->data = data;

	status = pthread_mutex_init(&heapThreadPayload->mutex, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed");
	}

	status = pthread_cond_init(&heapThreadPayload->cv, NULL);
	if (status != 0) {
		err_abort(status, "Cv initialize failed");
	}

	status = pthread_create(&heapThreadPayload->sortThread, NULL, heap_sort_thread_func, (void *)heapThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for heapSort ");
	}

	status = pthread_create(&heapThreadPayload->displayThread, NULL, display_thread_func, (void *)heapThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for display ");
	}

	status = pthread_join(heapThreadPayload->sortThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Heap Sort Thread Failed");
	}

	status = pthread_join(heapThreadPayload->displayThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Display Thread Failed :");
	}

	status = pthread_mutex_destroy(&heapThreadPayload->mutex);
	if (status != 0) {
		err_abort(status, "Pthread_mutex_destroy Failed for heap sort");
	}
	status = pthread_cond_destroy(&heapThreadPayload->cv);
	if (status != 0) {
		err_abort(status, "Pthread_cv_destroy Failed for heap sort");
	}

	free(heapThreadPayload);
}

/*<------------------------MergeSort ----------------------------------------->*/
void merge(int *arr, int left, int mid, int right)
{
	int l_count = mid - left + 1;
	int r_count = right - mid;
	int k = 0;

	int *l_arr = (int *)malloc(sizeof(int) * l_count);
	int *r_arr = (int *)malloc(sizeof(int) * r_count);

	int l_index = 0, r_index = 0;

	for (l_index = 0; l_index < l_count; l_index++) {
		l_arr[l_index] = arr[left + l_index];
	}

	for (r_index = 0; r_index < r_count; r_index++) {
		r_arr[r_index] = arr[mid + 1 + r_index];
	}

	l_index = 0;
	r_index = 0;

	while ((l_index  < l_count) && (r_index < r_count)){
		if (l_arr[l_index] > r_arr[r_index]) {
			arr[left + k] = r_arr[r_index];
			r_index++;
			k++;
		} else {
			arr[left + k ] = l_arr[l_index];
			l_index++;
			k++;
		}

	}

	while (l_index < l_count) {
		arr[left + k] = l_arr[l_index];
		k++;
		l_index++;
	}

	while (r_index < r_count) {
		arr[left + k] = r_arr[r_index];
		k++;
		r_index++;
	}

	free(l_arr);
	free(r_arr);
}


void merge_sort(int *arr, int left, int right)
{
	int mid;
	if (left < right) {
		mid = (left + right)/2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void* merge_sort_thread_func(void *arg)
{
	threadPayload_t *payload = (threadPayload_t *)arg;
	data_t *data = payload->data;
	int *arr = data->arr;
	int left = 0;
	int right = data->length - 1;

	int status;
	while(1) {
		status = pthread_mutex_lock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "mutex lock failed for merge sort");
		}

		if (payload->done) {
			status = pthread_mutex_unlock(&payload->mutex);
			if (status != 0) {
				err_abort(status, "mutex unlock failed for merge sort");
			}
			break;
		}

		while(payload->ready) {
			status = pthread_cond_wait(&payload->cv, &payload->mutex);
			if (status != 0) {
				err_abort(status, "CV wait failed for merge sort");
			}
		}

		merge_sort(arr, left, right);
		payload->ready = 1;
		status = pthread_cond_signal(&payload->cv);
		if (status != 0) {
			err_abort(status, "CV Signal failed ");
		}

		status = pthread_mutex_unlock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex unlocked Failed for merge Sort");
		}
		sleep(1);
	}
	return NULL;
}

void do_merge_sort(threadPayload_t *mergeThreadPayload, data_t *data)
{
	int status;
	if (mergeThreadPayload == NULL) {
		mergeThreadPayload = (threadPayload_t *)calloc(1, sizeof(threadPayload_t ));
	}
	mergeThreadPayload->ready = 0;
	mergeThreadPayload->type = "MergeSort";
	mergeThreadPayload->data = data;

	status = pthread_mutex_init(&mergeThreadPayload->mutex, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed");
	}

	status = pthread_cond_init(&mergeThreadPayload->cv, NULL);
	if (status != 0) {
		err_abort(status, "Cv initialize failed");
	}

	status = pthread_create(&mergeThreadPayload->sortThread, NULL, merge_sort_thread_func, (void *)mergeThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for mergeSort ");
	}

	status = pthread_create(&mergeThreadPayload->displayThread, NULL, display_thread_func, (void *)mergeThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for display ");
	}

	status = pthread_join(mergeThreadPayload->sortThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Merge Sort Thread Failed");
	}

	status = pthread_join(mergeThreadPayload->displayThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Display Thread Failed :");
	}

	status = pthread_mutex_destroy(&mergeThreadPayload->mutex);
	if (status != 0) {
		err_abort(status, "Pthread_mutex_destroy Failed for merge sort");
	}
	status = pthread_cond_destroy(&mergeThreadPayload->cv);
	if (status != 0) {
		err_abort(status, "Pthread_cv_destroy Failed for merge sort");
	}

	free(mergeThreadPayload);
}

/*<----------------------Quick Sort -------------------------------------->*/
int partition(int *arr, int left, int right)
{
	int key = arr[right];
	int i = left - 1;
	int j, pivot;

	for (j = left; j < right; j++) {
		if (arr[j] <= key) {
			i = i + 1;
			swap(arr, i, j);
		}
	}

	pivot =  i + 1;
	swap(arr, pivot, right);

	return pivot;
}

void quick_sort(int *arr, int left, int right)
{
	int pivot;
	if (left < right) {
		pivot = partition(arr, left, right);
		quick_sort(arr, left, pivot - 1 );
		quick_sort(arr, pivot + 1, right);
	}
}

void* quick_sort_thread_func(void *arg)
{
	threadPayload_t *payload = (threadPayload_t *)arg;
	data_t *data = payload->data;
	int *arr = data->arr;
	int left = 0;
	int right = data->length - 1;

	int status;
	while(1) {
		status = pthread_mutex_lock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "mutex lock failed for quick sort");
		}

		if (payload->done) {
			status = pthread_mutex_unlock(&payload->mutex);
			if (status != 0) {
				err_abort(status, "mutex unlock failed for quick sort");
			}
			break;
		}

		while(payload->ready) {
			status = pthread_cond_wait(&payload->cv, &payload->mutex);
			if (status != 0) {
				err_abort(status, "CV wait failed for quick sort");
			}
		}

		quick_sort(arr, left, right);
		payload->ready = 1;
		status = pthread_cond_signal(&payload->cv);
		if (status != 0) {
			err_abort(status, "CV Signal failed ");
		}

		status = pthread_mutex_unlock(&payload->mutex);
		if (status != 0) {
			err_abort(status, "Mutex unlocked Failed for quick Sort");
		}
		sleep(5);
	}
	return NULL;
}

void do_quick_sort(threadPayload_t *quickThreadPayload, data_t *data)
{
	int status;
	if (quickThreadPayload == NULL) {
		quickThreadPayload = (threadPayload_t *)calloc(1, sizeof(threadPayload_t ));
	}
	quickThreadPayload->ready = 0;
	quickThreadPayload->type = "QuickSort";
	quickThreadPayload->data = data;

	status = pthread_mutex_init(&quickThreadPayload->mutex, NULL);
	if (status != 0) {
		err_abort(status, "Mutex initialize failed");
	}

	status = pthread_cond_init(&quickThreadPayload->cv, NULL);
	if (status != 0) {
		err_abort(status, "Cv initialize failed");
	}

	status = pthread_create(&quickThreadPayload->sortThread, NULL, quick_sort_thread_func, (void *)quickThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for quickSort ");
	}

	status = pthread_create(&quickThreadPayload->displayThread, NULL, display_thread_func, (void *)quickThreadPayload);

	if (status != 0) {
		err_abort(status, "Thread Creation Failed for display ");
	}

	status = pthread_join(quickThreadPayload->sortThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Quick Sort Thread Failed");
	}

	status = pthread_join(quickThreadPayload->displayThread, NULL);
	if (status != 0) {
		err_abort(status, "Join Display Thread Failed :");
	}

	status = pthread_mutex_destroy(&quickThreadPayload->mutex);
	if (status != 0) {
		err_abort(status, "Pthread_mutex_destroy Failed for quick sort");
	}
	status = pthread_cond_destroy(&quickThreadPayload->cv);
	if (status != 0) {
		err_abort(status, "Pthread_cv_destroy Failed for quick sort");
	}

	free(quickThreadPayload);
}

int main()
{
	data_t *Hdata, *Mdata, *Qdata;
	Hdata = (data_t *)calloc(1, sizeof(data_t ));
	Mdata = (data_t *)calloc(1, sizeof(data_t ));
	Qdata = (data_t *)calloc(1, sizeof(data_t ));
	Hdata->length = 50;
	Hdata->size = 50;
	Mdata->length = 50;
	Mdata->size = 50;
	Qdata->size = 50;
	Qdata->length = 50;
	Hdata->arr = (int *)calloc(50, sizeof(int));
	Mdata->arr = (int *)calloc(50, sizeof(int));
	Qdata->arr = (int *)calloc(50, sizeof(int));
	threadPayload_t *heapSortPayload = NULL;
	threadPayload_t *mergeSortPayload = NULL;
	threadPayload_t *quickSortPayload = NULL;
	
	do_generate_array(Hdata);
	do_generate_array(Mdata);
	do_generate_array(Qdata);
	/*
	heap_sort(data);
	merge_sort(data->arr, 0, 49);
	quick_sort(data->arr, 0, 49);
	printf("After Output \n");
	print_array(data);
	*/
	do_heap_sort(heapSortPayload, Hdata);
	do_merge_sort(mergeSortPayload, Mdata);
	do_quick_sort(quickSortPayload, Qdata);
	printf("<-------------------------------------------------------------------------------------->\n");
	printf("<--------------- merge sort ----------------------->\n");
	print_array(Mdata);
	printf("<--------------- Heap sort ----------------------->\n");
	print_array(Hdata);
	printf("<--------------- Quick sort ----------------------->\n");
	print_array(Qdata);

	free(Hdata->arr);
	free(Hdata);
	free(Mdata->arr);
	free(Qdata->arr);
	free(Mdata);
	free(Qdata);
	printf ("I am done\n");
	return 0;
}

