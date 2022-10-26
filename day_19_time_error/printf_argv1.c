/* printing argv[1] with proper error handling */

/* from: https://stackoverflow.com/a/9748431/12282296, https://stackoverflow.com/a/504039/12282296 */

#include <stdio.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX, INT_MIN
#include <stdlib.h>  // for strtol
#include <string.h>  // for strerror

int main(int argc, char *argv[])
{
    char *p;
    int num;
    long conv;

    errno = 0;
    if (argc == 2) {
        // "stay away from atoi()"
        // https://stackoverflow.com/a/7021750/12282296
        conv = strtol(argv[1], &p, 10);
    } else {
        printf("Error. Wrong number of arguments. %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Check for errors: e.g., the string does not represent an integer
    // or the integer is larger than int
    if (errno != 0 || *p != '\0' || conv > INT_MAX || conv < INT_MIN) {
        printf("Oops! Something went wrong.\nError: %s\nExiting program ...\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else {
        // No error
        num = conv;     // note: demotion is not a problem here, since we checked "conv < INT_MIN" before!
        printf("%d\n", num);
    }

    return 0;
}