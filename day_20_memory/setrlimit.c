/*  setrlimit() */
/*  official doc: https://man7.org/linux/man-pages/man2/getrlimit.2.html */

/*  Using this code: */
/*  Use "./setrlimit -l" to cause Segmentation fault! */

/*  code from: https://stackoverflow.com/a/4118556 */

/*  https://stackoverflow.com/a/9154138 */
/*  "On Linux, within your C program, use setrlimit() to set your program's 
    execution environment limits. When you run out of memory, for instance, 
    then calls to malloc() will return NULL etc." */

#include <stdio.h>
#include <sys/resource.h>

void foo(void);

int main(int argc, char *argv[]) {
        struct rlimit lim = {1, 1};     // {soft limit, hard limit} in bytes 
                                        // see https://man7.org/linux/man-pages/man2/getrlimit.2.html

        if (argc > 1 && argv[1][0] == '-' && argv[1][1]=='l') {
                printf("limiting stack size\n");
                if (setrlimit(RLIMIT_STACK, &lim) == -1) {      // RLIMIT_STACK: stack; RLIMIT_DATA: heap; RLIMIT_AS: Virtual Memory
                        printf("rlimit failed\n");
                        return 1;
                }
        }

        foo();

        return 0;
}

void foo() {
        /**
         * @brief allocates more space in the stack than possible causing a segfault
         * 
         */

        unsigned ints[32768];

        printf("foo: %u\n", ints[2047]=42);
}