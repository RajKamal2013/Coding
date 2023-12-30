#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE         27

int main() {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 5678;


	if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		perror("shmget error");

	if ((shm = shmat(shmid, NULL, 0)) == (char *) - 1)
		perror("shmat error ");

	s = shm;

	for (c = 'a'; c <= 'z'; c++)
		*s++ = c;



	exit (0);
}
