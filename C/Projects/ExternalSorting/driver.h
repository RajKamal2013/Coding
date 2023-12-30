/****************************** FILE IO APIs **************************************/
#include "debug.h"
#include <pthread.h>

#define OUTPUT "output.txt"
#define FILE_COUNT 5
#define ARRAY_SIZE 50
#define ARRAY_LIMIT 1000

//char *files[FILE_COUNT] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
int fd[FILE_COUNT];
int fd_complete[FILE_COUNT];

pthread_cond_t fd_cv[FILE_COUNT];
pthread_mutex_t fd_mutex[FILE_COUNT];
pthread_t fd_tid[FILE_COUNT];

/* Using aio -> posix */
void signal_the_thread(int filedes);
//void fd_aio_completion_handler(sigval_t sigval);
void send_data_to_file(int fd);
void prepare_data_async();
void *thread_func(void * arg);
void dump_to_file_and_sort();
int check_fd_validity(int fd);
/*
int write_buf_via_poll();
int write_buf_via_select();
int write_buf_via_aio();
int read_file(const char *fileName);
*/



/************************* Sorting APIs ******************************************/



