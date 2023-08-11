#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "asyncIo.h"
#include "debug.h"

int main()
{
	int w_fd, i, r_fd ;
	int count = 500;
	size_t offset, off;

	/* ------------------Writing Integer-------------------*/

	w_fd = open("AioTest.txt", O_CREAT | O_APPEND | O_RDWR, S_IRWXU | S_IRWXO | S_IRWXG );
	if (w_fd == -1) {
		errno_abort("Not able to open file");
	}
	int arr[count];
	printf("Array Created \n");
	for (i = 0;i < count; i++) {
		arr[i] = 1000 + i;
		printf("%d ", arr[i]);
	}
	printf("\n");
	offset  = lseek(w_fd, 0, SEEK_END);
	write_to_file(w_fd, (void *)arr, sizeof(arr), offset, 4);
	close(w_fd);



	/* -------------------------Reading Integer in 1 Go------------------*/
	r_fd = open("AioTest.txt", O_RDONLY, S_IRUSR | S_IROTH | S_IRGRP);
	if (r_fd == -1) {
		errno_abort("Not able to open file");
	}
	int arr1[count];
	memset(arr1, '\0', sizeof(arr1));
	offset  = lseek(r_fd, 0, SEEK_SET);
	read_from_file_async(r_fd, (void *)arr1, sizeof(arr1), offset, 1);

	printf("Array Read \n");
	for (i = 0; i < count; i++) {
		printf ("%d ", arr1[i]);
	}
	printf("\n");
	close(r_fd);

	/*"----------------------Reading Data in n chunks -----------------*/
	r_fd = open("AioTest.txt", O_RDONLY, S_IRUSR | S_IROTH | S_IRGRP);
	if (r_fd == -1) {
		errno_abort("Not able to open file");
	}
	int chunks = 4;
	int batch = count/4;
	int batch_rarr[batch];
	offset = 0;
	off = 0;
	int index; 
	for (i = 0; i < chunks - 1 ; i++) {
		offset = lseek(r_fd, off, SEEK_SET);
		memset(batch_rarr, '\0', sizeof(batch_rarr));
		read_from_file_async(r_fd, (void *)batch_rarr, sizeof(batch_rarr), offset, 1);
		off = off + sizeof(batch_rarr);
		printf("Array Read in %d Chunk: \n", i);
		for (index = 0; index < batch; index++) {
			printf ("%d ", batch_rarr[index]);
		}
		printf ("\n");
	}
	close(r_fd);

	/* ---------------------- Writing Char ----------------------- */
	w_fd = open("AioTest1.txt", O_CREAT | O_APPEND | O_RDWR, S_IRWXU | S_IRWXO | S_IRWXG );
	if (w_fd == -1) {
		errno_abort("Not able to open file");
	}
	char carr[] = "Hi This is Raj Kamal. I want to do best in coding. I want to do coding as Art.";
	printf("\n");
	offset  = lseek(w_fd, 0, SEEK_END);
	write_to_file_async(w_fd, (void *)carr, sizeof(carr) + 1, offset, 1);
	printf ("Data Written : %s \n", carr);
	close(w_fd);

	/* ------------------- Reading Char ----------------------- */
	r_fd = open("AioTest1.txt", O_RDONLY, S_IRUSR | S_IROTH | S_IRGRP);
	if (r_fd == -1) {
		errno_abort("Not able to open file");
	}
	char *carr1 = (char *)malloc(sizeof(carr));
	memset(carr1, '\0', sizeof(carr));
	offset = 0;
	offset  = lseek(w_fd, 0, SEEK_SET);
	read_from_file_async(r_fd, (void *)carr1, sizeof(carr) + 1, offset, 1);
	printf ("Data Read : %s \n", carr1);
	close (r_fd);

	return 0;
}
