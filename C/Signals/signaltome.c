#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


static void sig_usr1Handler(int signo) 
{
	if (signo == SIGUSR1) {
		printf(" I raised myself ");
	} else {
		fprintf(stderr, "ERR:API %s OOPS kernel did it again, I am"
			" not the signal handler for the %s signal %d ", 
			__func__, sys_siglist[signo], signo);
		exit(EXIT_FAILURE);
	} 
}


int main() 
{
	if(signal(SIGUSR1, SIG_IGN) != SIG_IGN)  {
		if (signal(SIGUSR1, sig_usr1Handler) == SIG_ERR) {
			fprintf(stderr, "ERR: API %s Hit issue while registering"
				" for signal %s \n", __func__, sys_siglist[SIGUSR1]);
			exit(EXIT_FAILURE);
		}
	}

	raise(SIGUSR1);
	return 0;
}
