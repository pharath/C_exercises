/* Implicit Conversion by Assignment */
/* p570: Must cast a void pointer before dereferencing it */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *vp;
    int x;

    vp = malloc(sizeof(int));
    x = 120;
    
    /* Must cast a void pointer before dereferencing it */
    *(int*)vp = x;
    /* folgendes geht nicht! */
    // *vp = x;
    
    printf("%d\n", * (int*)vp);
    
    free(vp);
}