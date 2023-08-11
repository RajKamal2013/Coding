#include "apue.h"
#include <errno.h>
#include <stdarg.h>

static void err_doit (int, int, const char *, va_list);

/* Non Fatal related to system call */
/* print the message and return */
void 
err_ret (const char *fmt, ...) {
	va_list ap; 
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

/* Fatal error related to system call */
/* print the message and return */
void 
err_sys(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}

/* Non fatal error unrelated to a system call */
/* Error code passed as explicit parameter */
/* Print the message and return */
void 
err_cont(int error, const char *fmt, ...) {
	va_list ap;
	va_start (ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
}


/* Fatal error unrelated to a system call */
/* Error code passed as explicit parameter */
/* Print the message and terminate */
void 
err_exit(int error, const char *fmt, ...) {
	va_list ap; 
	va_start(ap, fmt);
	err_doit(1, error, fmt, ap);
	va_end(ap);
	exit(1);
}

/* Fatal error related to system call */
/* print the message, dump core and terminate */
void 
err_dump(const char *fmt, ...) {
	va_list ap; 
	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	abort(); /* creates dump */
	exit(1);
}

/* Nonfatal error unrelated to a system call */
/* print a message and return */
void
err_msg (const char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
}

/* Fatal error unrelated to a system call */
/* Print a message and terminate */
void 
err_quit(const char *fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	err_doit(0, 0, fmt, ap);
	va_end(ap);
	exit(1);
}

/* Print the message and return to caller */
/* caller specifies error flag */
static void 
err_doit (int errnoflag, int error, const char *fmt, va_list ap) {
	char buf[MAXLINE];
	vsnprintf(buf, MAXLINE-1, fmt, ap);
	if (errnoflag)
		sprintf(buf_strlen(buf), MAXLINE-strlen(buf)-1, ": %s", 
				strerror(error));
	strcat(buf, "\n");
	fflush(stdout); /* in case stdout and stderr are same */
	fputs(buf, stderr);
	fflush(NULL); /* flushes all stdio output streams */
}

