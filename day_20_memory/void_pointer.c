/* from: https://overiq.com/c-programming-101/void-pointers-in-c/ */

/* void pointer */
/* if a pointer is of type pointer-to-int or (int *) then 
   it can hold the address of the variable of type int only. It would 
   be incorrect, if we assign an address of a float variable to a 
   pointer of type pointer-to-int. But void pointer is an exception 
   to this rule. A void pointer can point to a variable of any data type */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *vp;

    int a = 100, *ip;
    ip = &a;
    float f = 12.2, *fp;
    fp = &f;
    char ch = 'a', *cp;
    cp = &ch;

    vp = &a; // ok
    printf("%d\n", * (int*)vp);
    vp = ip; // ok
    printf("%d\n", * (int*)vp);
    vp = fp; // ok
    printf("%.2f\n", * (float*)vp);
    vp = cp; // ok
    printf("%c\n", * (char*)vp);

    // ip = &f; // wrong since type of ip is pointer-to-int
    // fp = ip; // wrong since type of fp is pointer-to-float

    return 0;
}