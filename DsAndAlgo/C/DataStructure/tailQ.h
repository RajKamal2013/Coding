#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

typedef int bool;
#define true 1
#define false 0

/* ----------------------- Queue1 Generic Implementation ----------------------*/
/* Common data that will be the part of any DS I am implementin */
typedef struct elmt_common_data {
	int ref;			// till ref does not reach 0, we wont delete the entry.
	bool valid;  			// If true -> entry is sane ow entry is deleted and waiting to get free .
	int data_gen;			// every op will increase the data gen.
	pthread_mutex_t lock;
	void *container;
} elmt_common_data_t;

typedef struct Queue1_Elmt {
	struct elmt_common_data *c_data;
	void *data;
	struct Queue1 *owner;
	struct Queue1_Elmt *next;
	void (*free_func)(void *data);  	// Free function if user wants us to take care of freeing the data inside entry 
	int (*compare_func)(void *data1, void *data2); // compare function 
} queue1_elmt_t;

typedef struct head_common_data {
	uint32_t capacity; /* -1 for infinite size */
	uint32_t size;
	bool threadsafe;
	pthread_mutex_t lock;
	void (*free_func)(void *data);  	// Free function if user wants us to take care of freeing the data inside entry 
	int (*compare_func)(void *data1, void *data2); // compare function 
} head_common_data_t;


typedef struct Queue1 {
	struct head_common_data *c_data;
	queue1_elmt_t *head;
	queue1_elmt_t *tail;
} queue1_t;

queue1_t queue_recycle_bin;  //* A thread will run and will free these */

typedef struct queue1_itr_cookie {
	queue1_t *Q;
	queue1_elmt_t *curr;
	int curr_data_gen;
} queue1_itr_cookie_t;

int elmt_lock(pthread_mutex_t *lock);
int elmt_unlock(pthread_mutex_t *lock);
void add_ref(void *data, bool safe);
void dec_ref(void *data, bool safe);
elmt_common_data_t *
init_elmt_common_data(void *data);
void free_elmt_common_data(void *data);
head_common_data_t*
init_head_common_data(uint32_t capacity,
			   uint32_t size, bool threadsafe);
void free_head_common_data(void *data);
void free_queue1_elmt(void *data);
queue1_t * queue1_init(int capacity, bool threadsafe,
		 void (*free_func)(void *),
		 int (*compare_func)(void *, void *));

void queue1_destroy(queue1_t  *Q);
bool queue1_is_full(queue1_t *Q);
bool queue1_is_empty(queue1_t *Q);
void* queue1_top(queue1_t *Q);
uint32_t queue1_size(queue1_t *Q);
void queue1_enqueue(queue1_t *Q, void *data);
void* queue1_dequeue(queue1_t *Q);

/* For each Like API for queue */


/* ----------------------- Queue1 Linux Container Implementation ----------------------*/
/*
typedef struct Queue2_t {
	struct Queue2_t *head;
	struct Queue2_t *tail;
	uint32_t size; *//* -1 for infinite size 
} Queue2_t;
*/



	
