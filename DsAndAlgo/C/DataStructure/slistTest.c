#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "slist.h"
#include "debug.h"


int main() 
{
	int i = 0;
	int *var = NULL;
	slist_t *list = NULL;
	list = slist_init(false, NULL, NULL);

	printf("Pushing \n");
	for (i = 0; i < 10; i++) {
		var = (int *)malloc(sizeof(int));
		*var = i;
		printf(" %d", *var);
		slist_push_back(list, var);
	}
	printf("\n Poping \n");	
	for (i = 0;i < 10; i++) {
		var = (int *)slist_pop_back(list);
		printf (" %d ", *var);
	}
	printf("\n");

	return 0;
}
