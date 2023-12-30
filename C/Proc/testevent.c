#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/eventfd.h>


int main()
{
	pid_t child;
	int efd = eventfd(1, EFD_NONBLOCK);
	if (efd == -1) {
		fprintf(stderr, "ERR, Not able to create eventfd %s error %d \n",
			strerror(errno), errno);
		exit(EXIT_FAILURE);
	} 
	
	child = fork();
	if (child == -1) {
		fprintf(stderr, "ERR, Not able to fork %s error %d \n", strerror(errno), errno);
		exit(EXIT_FAILURE);
	} else if (child == 0) {
		int cret;
		int cval = 0;
		printf (" I am child \n");
		cret = read(efd, &cval, sizeof(int));
		printf("Value read %d \n", cval);
	} else {
		int pval = 0;
		int pret;
		int status;
		pret = read(efd, &pval, sizeof(int));
		printf("Value read %d \n", pval);
		waitpid(child, &status, WNOHANG);
		if (WIFEXITED (status)) {
			printf ("Normal termination with exit status=%d\n",
				WEXITSTATUS (status));
		}
		if (WIFSIGNALED (status)) {
			printf ("Killed by signal=%d%s\n",
				WTERMSIG (status), WCOREDUMP (status) ?
				" (dumped core)" : "");
		}
		if (WIFSTOPPED (status)) {
			printf ("Stopped by signal=%d\n",
				WSTOPSIG (status));
		}

	}

	return 0;
}
