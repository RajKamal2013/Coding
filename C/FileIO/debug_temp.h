#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef DEBUG1
#define D if(1) 
#else
#define D if(0) 
#endif

/* Usage */
/* D printf("x=%0.3f\n",x); */ 


/* ------------------------Below Not Used ------------------------ */
/*
#ifdef DEBUG0
#define debug_printf(args ...) fprintf(dfd0, args)
#else 
#define debug_printf(args ...)
#endif
#ifdef DEBUG
#define DPRINTF(fmt, ...) 									\
*/
/*
do { 												\
	if (DEBUG) {										\
		fprintf(dfd, "%s:%d:%s(): " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__); 	\
	}											\
} while (0)
#else
#define DPRINTF(fmt, ...) do {} while(0)
*/
/*
#ifdef DEBUG1 
#define DPRINTF1(int nHowMany, ...) debug_printf1(int nHowMany, ...)
#else
#define DPRINTF1(int nHowMany, ...) do {} while (0)
#endif 

void debug_printf1(int nHowMany, ...) 
{
	int count = nHowMany;
	va_list dbgPointer;
	va_start(dbgPointer, count);
	int i;

	for (i = 0; i < count; i++) {
		printf ("%s", va_arg(dbgPointer, char *));
	}
	va_end(dbgPointer);
}
*/
/*
#ifdef DEBUG2 
#define DPRINTF2(msg) debug_printf2 msg
#else
#define DPRINTF2(msg) (void) 0 
#endif 
*/
/* U need to add double paranthesis */
/* DPRINTF2(("argv[0] is %s, argc is %d\n", argv[0], argc)); */
/*
void debug_printf2(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(dfd2, fmt, args);
	va_end(args);
}
*/
/*
#ifdef DEBUG3
#define DPRINTF3(fmt, ...) fprintf(dfd3, fmt, __VA_ARGS__)
#else
#define DPRINTF3(fmt, ...) do {} while (0)
#endif
*/


/*
#define DPRINTF5(FMT, ARGS...)				\
do { 							\
    if (DEBUG5) 					\
	fprintf(dfd5, "%s:%d " FMT "\n", __FUNCTION__, __LINE__, ## ARGS); \
  } while (0)

*/
