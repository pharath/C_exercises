/* get a human-readable version of the current local time */
/* Warning: ctime() and asctime() share the array which holds the 
time string, i.e. if either one of these functions is called, 
the content of the array is overwritten */

#include <time.h>
#include <stdio.h>

int main(void)
{
    time_t mytime;
    mytime = time(NULL);
    printf(ctime(&mytime));
    // puts(ctime(&mytime));    // geht auch!

    return 0;
}