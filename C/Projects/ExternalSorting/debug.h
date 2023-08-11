#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <string.h>
#include <sys/types.h>


#ifdef DEBUG 
#define DPRINTF(arg) printf(arg)
#else
#define DPRINTF(arg)
#endif 

#define err_abort(code, text) 							\
do {										\
	fprintf(stderr, "%s at %s in %s at %d , %s Error %d \n",		\
		 text, __FILE__, __func__, __LINE__, strerror(code), code); 	\
	abort();								\
} while (0)

#define errno_abort(text)							\
do {										\
	fprintf(stderr, "%s at %s in %s at %d , %s Error %d \n",		\
		 text, __FILE__, __func__, __LINE__, strerror(code), code); 	\
	abort();								\
} while (0)


