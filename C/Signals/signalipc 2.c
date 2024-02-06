#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>

/* I am stuck I cant send child information in signal handler */
pid_t child;

static void sigterm_child_handler(int signo) 
{
	static int sigtermvar = 0;
	if (signo == SIGTERM) {
		printf("Yo I got signal %s ", sys_siglist[SIGTERM]); 
		if (sigtermvar == 0) {
			printf(" I am not listening to Parent \n");
		} else if (sigtermvar < 10) {
			printf("Yo I am ignoring again \n");
		} else {
			printf ("Yo I gave up \n");
			signal(SIGTERM, SIG_DFL);
		}
		sigtermvar++;
	} else {
		printf("Oops I am not the handler for sigal %s, Kernel needs"
			" to remember it \n", sys_siglist[SIGTERM]);
	}
}

static void sigterm_parent_handler(int signo)
{
	static int sigtermvar = 0;
	int ret; 
	if (signo == SIGTERM) {
		printf("Yo I got signal %s ", sys_siglist[SIGTERM]); 
		if (sigtermvar == 0) {
			printf(" I am ignoring this, first I want my child to respond \n");
			ret = kill(child, SIGTERM);
			if (ret) {
				fprintf(stderr, "ERR :API() %s not able to send"
					" SIGTERM to child %s Error %d\n", __func__,
					strerror(errno), errno);
				exit(EXIT_FAILURE);
			}
		} else if (sigtermvar < 12) {
			printf("Yo I am ignoring again \n");
			printf(" I am ignoring this, I want my child to respond now \n");
			ret = kill(child, SIGTERM);
			if (ret) {
				fprintf(stderr, "ERR :API() %s not able to send"
					" SIGTERM to child %s Error %d\n", __func__,
					strerror(errno), errno);
				exit(EXIT_FAILURE);
			}
		} else {
			printf ("Yo I gave up, killing both child and parent \n");
			signal(SIGTERM, SIG_DFL);
		}
		sigtermvar++;
	} else {
		printf("Oops I am not the handler for sigal %s, Kernel needs"
			" to remember it \n", sys_siglist[SIGTERM]);
	}
}

int main()
{
	child = fork();
	if (child == -1) {
		fprintf(stderr, "ERR:API %s fork() failed, %s Error %d \n",
			__func__, strerror(errno), errno);
		exit(EXIT_FAILURE);
	} else if (!child) { /* Child */
		printf("I am Child %d \n", child);
		/* SIG_TERM -> kill -15 <pid> */
		if (signal(SIGTERM, SIG_IGN) != SIG_IGN) {
			if(signal(SIGTERM, sigterm_child_handler) == SIG_ERR)
			{
				fprintf(stderr, "ERR, API %s, Not able to "
					"register signal %s , %s ERROR, %d \n",
					__func__, sys_siglist[SIGTERM],
					strerror(errno), errno);
				exit(EXIT_FAILURE);
			}
		}
		for (; ;) {
			pause();
		}
		//exit(EXIT_SUCCESS);
	} else { /* parent*/
		int status;
		printf("I am parent and my child is %d\n", child);
		/* SIG_TERM -> kill -15 <pid> */
		if (signal(SIGTERM, SIG_IGN) != SIG_IGN) {
			if(signal(SIGTERM, sigterm_parent_handler) == SIG_ERR)
			{
				fprintf(stderr, "ERR, API %s, Not able to "
					"register signal %s , %s ERROR, %d \n",
					__func__, sys_siglist[SIGTERM],
					strerror(errno), errno);
				exit(EXIT_FAILURE);
			}
		}
		//exit(EXIT_SUCCESS);
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
		if (WIFCONTINUED (status)) {
			printf ("Continued\n");
		}
		for (; ;) {
			pause();
		}
	}
	return 0;
}
