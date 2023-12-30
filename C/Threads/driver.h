#include <stdio.h>
#include <string.h>


/****************************** FILE IO APIs **************************************/
#define FILE1 "file1.txt"
#define FILE2 "file2.txt"
#define FILE3 "file3.txt"
#define FILE4 "file4.txt"
#define FILE5 "file5.txt"
#define OUTPUT "output.txt"

int write_buf_via_poll();
int write_buf_via_select();
int write_buf_via_aio();
int read_file(const char *fileName);



/************************* Sorting APIs ******************************************/



