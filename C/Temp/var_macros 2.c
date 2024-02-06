#include <stdio.h>
#include <string.h>

typedef struct transaction {
    long time;
} transaction_t;

typedef enum {
    IMP,
    DBG,
    INFO
} my_log_level;

static void 
my_trace(my_log_level level, const char *func, transaction_t trans, char * msg);

#define MY_TRACE(level, ...)                            \
    do {                                                \
        char buffer[1024];                              \
        sprintf(buffer, # __VA_ARGS__);                 \
        my_trace(level, __FUNCTION__, trans, buffer);   \
    } while(0)

#define MY_TRACE1(level, ...)              my_trace(level, __FUNCTION__, trans, __VA_ARGS__)



static void
my_trace(my_log_level level, const char *func, transaction_t trans,  char *msg)
{
    printf("level : %d, API: %s, TIME: %ld - %s, \n", level, func, trans.time, msg);
}


static int
log_demo1() 
{
    transaction_t trans;
    trans.time = 1000;
    my_log_level level = IMP;
    
    MY_TRACE(level, "Hi I Am", "raj Kamal");

    return trans.time;
}

static int
log_demo2() 
{
    transaction_t trans;
    trans.time = 10001;
    my_log_level level = DBG;
    
    MY_TRACE(level, "Hi I Am", "new", "raj Kamal2");

    return trans.time;
}


int main() 
{
    int ret = 0;
    printf("Lets work on macros \n");
    ret = log_demo1();
    printf("return1 : %d\n", ret);

    ret = log_demo2();
    printf("return2 : %d\n", ret);

    return 0;
}



