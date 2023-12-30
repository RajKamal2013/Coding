#include <stdio.h>
#include "driver.h"
#include "debug.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
/*
<<<<<<< HEAD
	char *files[FILE_COUNT]= {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt"};
=======
	char *files[FILE_COUNT]= {"sfile1.txt", "sfile2.txt", "sfile3.txt", "sfile4.txt", "sfile5.txt"};
>>>>>>> 5bf8a18e871b3c59bf7b01fe3ddad6930a9bef4d
	int i = 0;
	for ( i = 0; i < FILE_COUNT; i++) {
		printf("File : %s \n", files[i]);
		fd[i] = open(files[i], O_CREAT | O_EXCL | O_RDWR, S_IWUSR  | S_IWUSR );
		if (fd[i] == -1 ) {
			abort();
		}
	//	send_data_to_file(fd[i]);
	}
	printf ("done");
*/
	prepare_data_async();
	dump_to_file_and_sort();

	return 0;
}

