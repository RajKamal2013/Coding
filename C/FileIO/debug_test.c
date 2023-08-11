#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "debug.h"

int dfd0;

int main() 
{
	int var = 2;
	dfd0 = open("dbg.txt", O_CREAT | O_WRONLY);
	D printf("DBG: API :%s, var is %d \n", __func__, var);
	//debug_printf("DBG: API :%s, var is %d \n", __func__, var);
	return 0;
}
