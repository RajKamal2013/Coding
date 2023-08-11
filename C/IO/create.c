/* C Program to create a random file of size given in args */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


#define	FILENAMESIZE 100
#define NUMBEROFFSEET 10
#define ALPHABETOFFSET 26


int main(int argc, char *argv[]) {
	int i ;

	int size;
	char name[FILENAMESIZE];
	char *buff, *temp_buff;;

	printf ("Command Line Argument ");
	for (i = 0; i <argc; i++)
		printf("%d . %s  \n", i,  argv[i]);

	/* Parsing command line argument to get size and name of file */
	size = atoi(argv[1]);
	memcpy(name, argv[2], FILENAMESIZE);
	printf ("File Name : %s and File Size : %d ", name, size);

	/* Generate buffer of size "size" and fills with random character */

	buff = (char *) malloc(size * sizeof(char));
	if (!buff)
		perror("Malloc : Not able to create buf");
	temp_buff = buff;

	for (i = 0; i < size - 1; i = i++) {
		*temp_buff++ = (char ) (i % ALPHABETOFFSET + 'A');
		//(*temp_buff)++  = (char ) (i % NUMBEROFFSEET + '1');
		//(*temp_buff)++ = (char ) (i % ALPHABETOFFSET + 'a');
	}
	temp_buff ='\0';

	printf ("Buffer Content : %s", buff);


	return 0;
}
