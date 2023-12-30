#include <stdio.h>
#define TRACE_LOG(...)                         \
    do {                                       \
        char buffer[200];                      \
        sprintf(buffer, " " __VA_ARGS__);      \
        printf("%s\n", buffer);                \
    } while(0)

int main() {
    int i=1;
    TRACE_LOG("%s", "Sample macro");
    TRACE_LOG("%d %s", i, "Sample macro");
    TRACE_LOG("hi %i",i);
    TRACE_LOG("Hi you");
    TRACE_LOG();
    return 0;
}


/*   sprintf(buffer, " ", ## __VA_ARGS__);   */
/*   sprintf(buffer, ## __VA_ARGS__, " ");   */
