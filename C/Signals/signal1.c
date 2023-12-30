#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sigalrm_modified(int signo)
{
	if(signo == SIGALRM) {
		printf("Elapsed 10 seconds \n");
		printf("Yo !! I modified the alarm signal \n");
	//	exit(EXIT_SUCCESS);
	} else {
		fprintf(stderr, "ERR:API%s() , caught wrong signal %s for %s "
			"signal \n", __func__,  sys_siglist[signo],
			sys_siglist[SIGALRM]);
		exit(EXIT_FAILURE);
	}
}

/* After 10 ctrl_C , SIG_INT is back to defaule behaiviour */
static void sigint_modified(int signo) 
{
	static int var = 0;
	if (signo == SIGINT) {
		if (var == 0) {
			printf("Caught the SIGINT, Code interrupt by ctlr+C but did not"
				"let it happen, not quitting as expected \n");
		} else if (var < 10) {
			/* setting to ignore */
			printf("I am ignoring ctrl_C as now \n");
			//signal(SIGINT, SIG_IGN);
		} else {
			/* Getting to Default */
			signal(SIGINT, SIG_DFL);
		}
		var++;
		//exit(EXIT_SUCCESS);
	} else {
		fprintf(stderr, "ERR:API%s() , caught wrong signal %s for %s "
			"signal \n", __func__,  sys_siglist[signo],
			sys_siglist[SIGINT]);
		exit(EXIT_FAILURE);
	}
}


int main()
{
	/* Registering SIG_ALARM to the kernel */
	if (signal(SIGALRM, sigalrm_modified) == SIG_ERR) {
		fprintf(stderr, "ERR: API:%s Not able to modified the signal %s\n",
			__func__, sys_siglist[SIGALRM]);
		exit(EXIT_FAILURE);
	}
	if (signal(SIGINT, sigint_modified) == SIG_ERR) {
		fprintf(stderr, "ERR: API:%s Not able to modified the signal %s\n",
			__func__, sys_siglist[SIGINT]);
		exit(EXIT_FAILURE);
	}

	alarm(2);
	/* Other than alarm we raise/send the signal via  pause(), kill() and raise() */ 
	for (;;) {
		pause();
	}
	printf("We Quit the first one ");
	/* We tried reinstalling it but seems I cant do like this , I need to
	 * some hack inside the signal handler */
	// Trying to set ignore */
	/*
	signal(SIGINT, SIG_IGN);
	for (;;) {
		pause();
	}
	// Tryint to set to Default 
	signal(SIGINT, SIG_DFL);
	for (;;) {
		pause();
	}
	*/
	return 0;
}
