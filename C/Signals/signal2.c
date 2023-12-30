#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

static void modified_signal_handler(int signo)
{
	static int sigintvar = 0;
	static int sigtermvar = 0;
	if (signo  == SIGINT) {
		if (sigintvar == 0) {
			printf("Yo We caught the %s signal and we are not doing"
				" anything \n", sys_siglist[SIGINT]);
		} else if (sigintvar  < 10) {
			printf("Yo Not doing anything \n");
		} else {
			printf("Yo Agreed to Quit, Thanks for being patience \n");
			exit(EXIT_SUCCESS);
		}
		sigintvar++;
	} else if (signo == SIGTERM) {
		if (sigtermvar == 0) {
			printf("Yo We caught the %s signal and we are not doing"
				" anything \n", sys_siglist[SIGTERM]);
		} else if (sigtermvar  < 10) {
			printf("Yo Not doing anything \n");
		} else {
			printf("Yo Agreed to Quit, Thanks for being patience \n");
			exit(EXIT_SUCCESS);
		}
		sigtermvar++;
	} else {
		exit(EXIT_FAILURE);
	}
}

int main()
{
	/* Register only when signal is not ignored */
	/*
	 * 1. SIGINT
	 * 2. SIGTERM
	 * 3. SIGHUP
	 */
	/* 1. Register SIGINT --> ctrl + C */
	if (signal (SIGINT, SIG_IGN) != SIG_IGN) {
		if (signal (SIGINT, modified_signal_handler) == SIG_ERR) {
			fprintf(stderr, "ERR: API %s() not able to register %s "
				"signal \n", __func__, sys_siglist[SIGINT]);
			exit(EXIT_FAILURE);
		}
	}

	/* 2. Register SIGTERM --> kill -15 <pid>*/
	if (signal (SIGTERM, SIG_IGN) != SIG_IGN) {
		if (signal (SIGTERM, modified_signal_handler) == SIG_ERR) {
			fprintf(stderr, "ERR: API %s() not able to register %s "
				"signal \n", __func__, sys_siglist[SIGTERM]);
			exit(EXIT_FAILURE);
		}
	}

	/* 2. Register SIGHUP --> when process hung for long time <deadlock or sleep>*/
	if (signal (SIGHUP, SIG_IGN) == SIG_ERR) {
		fprintf(stderr, "ERR: API %s() not able to register %s "
			"signal \n", __func__, sys_siglist[SIGHUP]);
		exit(EXIT_FAILURE);
	}

	for (;;) {
		pause();
	}

	return 0;
}
