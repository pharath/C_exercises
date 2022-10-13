/* void pointer: */
/* pointer arithmetic with void pointers */

/* from: https://overiq.com/c-programming-101/void-pointers-in-c/ */

#include<stdio.h>
#define SIZE 10

int main()
{
    int one_d[5] = {12, 19, 25, 34, 46}, i;

    void *vp = one_d;

    for(i = 0; i < 5; i++)
    {
        printf("one_d[%d] = %d\n", i, *( (int *)vp + i ) );
    }

    // signal to operating system program ran fine
    return 0;
}