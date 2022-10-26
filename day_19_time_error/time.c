/* Usage of time() */
/* returns number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC */

#include <stdio.h>
#include <time.h>

int main ()
{
    // using a NULL pointer:
    // time_t sec;
    // sec = time (NULL);

    // or alternatively:
    // using the *timeptr (ptr_now points to the address of sec)
    time_t sec;
    time_t *ptr_now = &sec;
    time(ptr_now);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);
    return 0;
}
