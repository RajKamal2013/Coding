#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

typedef int bool;
#define true 1
#define false 0

#define ITER_FLAG_LOCK 1

/* Common data that will be the part of any DS I am implementin */
typedef struct elmt_common_data {
	int ref;			// till ref does not reach 0, we wont delete the entry.
	bool valid;  			// If true -> entry is sane ow entry is deleted and waiting to get free .
	int data_gen;			// every op will increase the data gen.
	pthread_mutex_t lock;
	void *container;
} elmt_common_data_t;

typedef struct elmt {
	struct elmt_common_data *c_data;
	void *data;
	void *owner;
	struct elmt *next;
	struct elmt *prev;
	void (*free_func)(void *data);          // Free function if user wants us to take care of freeing the data inside entry
	int (*compare_func)(void *data1, void *data2); // compare function
} elmt_t;

typedef struct head_common_data {
	uint32_t capacity; /* -1 for infinite size */
	uint32_t size;
	bool threadsafe;
	pthread_mutex_t lock;
	void (*free_func)(void *data);  	// Free function if user wants us to take care of freeing the data inside entry 
	int (*compare_func)(void *data1, void *data2); // compare function 
} head_common_data_t;

typedef struct iter_cookie {
	elmt_t *curr;
	void *container;
	char *type;
	elmt_t *head;
	uint32_t curr_datagen;
	uint32_t flags;
	bool ref_taken;
	void (*display_func)(void *data);
} iter_cookie_t;

/* Shall I add a argument saying lock is already taken by caller !!! => */
int elmt_lock(pthread_mutex_t *lock);
int elmt_unlock(pthread_mutex_t *lock);
void add_ref(void *data, bool safe);
void dec_ref(void *data, bool safe);
void dec_ref_without_free(void *data, bool safe);
elmt_common_data_t *
init_elmt_common_data(void *data);
void free_elmt_common_data(void *data);
head_common_data_t*
init_head_common_data(uint32_t capacity,
	uint32_t size, bool threadsafe);
void free_head_common_data(void *data);
elmt_t* init_elmt(void *owner, void *data);
void free_elmt(void *data);
void free_elmt_without_data(void *data);
iter_cookie_t* iter_init(void *container, char *type, uint32_t flags, void (*display_func)(void *));
void iter_done(iter_cookie_t *cookie);
