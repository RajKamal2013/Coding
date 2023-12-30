#include <stdio.h>
#include <string.h>
#include "debug.h"
#include "tailQ.h"

int main() 
{
	int i = 0;
	queue1_t *Q = NULL;
	Q = queue1_init(10, 1, NULL, NULL);
	int *temp;
	for (i = 0;i < 10; i++) {
		temp = (int *) malloc(sizeof(int));
		*temp = i;
		queue1_enqueue(Q, temp);
	}

	for (i = 0; i < 10; i++) {
		temp = queue1_dequeue(Q);
		printf("Head of Queue : %d\n", *temp);
		free(temp);
	}

	return 0;
}
