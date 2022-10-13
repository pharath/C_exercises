/* setrlimit() */
/* official doc: https://man7.org/linux/man-pages/man2/getrlimit.2.html */

/* code from: https://stackoverflow.com/questions/4118016/set-stack-size-with-setrlimit-and-provoke-a-stack-overflow-segfault */

/* https://stackoverflow.com/questions/9154115/how-to-set-memory-use-limit-when-writing-c-program-and-what-happens-if-once-it-e */
/* "On Linux, within your C program, use setrlimit() to set your program's 
   execution environment limits. When you run out of memory, for instance, 
   then calls to malloc() will return NULL etc." */

/* Use "./setrlimit -l" to cause Segmentation fault! */

#include <stdio.h>
#include <sys/resource.h>

void foo(void);

int main(int argc, char *argv[]) {
        struct rlimit lim = {1, 1};


        if (argc > 1 && argv[1][0] == '-' && argv[1][1]=='l') {
                printf("limiting stack size\n");
                if (setrlimit(RLIMIT_STACK, &lim) == -1) {
                        printf("rlimit failed\n");
                        return 1;
                }
        }

        foo();

        return 0;
}

void foo() {
        unsigned ints[32768];

        printf("foo: %u\n", ints[2047]=42);
}