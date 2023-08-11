#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



typedef struct teststruct_ {
	int id;
	char *data;
	char buff[28];
} teststruct;


void test_struct(void) 
{
	char *name;
	teststruct *test = (teststruct *) malloc(sizeof(teststruct));
	test->id = 1;
	test->data = "Hi Its me ! Oops I am still here //n";
	strcpy(test->buff, "Hi Its me the second one ");
	name = test->data;
	printf("Data Before Deleting : %s\n", name);
	free(test);
	printf("Data After Deleting : %s\n", name);
}

int main() {
	(void) test_struct();
	return 0;
}
