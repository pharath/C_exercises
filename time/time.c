/* Usage of time() */
/* returns number of seconds elapsed since 00:00 hours, Jan 1, 1970 UTC */

#include <stdio.h>
#include <time.h>
int main ()
{
    time_t sec;
    sec = time (NULL);

    printf ("Number of hours since January 1, 1970 is %ld \n", sec/3600);
    return 0;
}
