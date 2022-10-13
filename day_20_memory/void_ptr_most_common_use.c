/* Using type void pointers. */

#include <stdio.h>

void half(void *pval, char type);

int main(void)
{
    /* Initialize one variable of each type. */

    int i = 20;
    long l = 100000;
    float f = 12.456;
    double d = 123.044444;

    /* Display their initial values. */

    printf("\n % d", i);
    printf("\n % ld", l);
    printf("\n % f", f);
    printf("\n % lf\n\n", d);

    /* Call half() for each variable. */

    half(&i, 'i');
    half(&l, 'l');
    half(&d, 'd');
    half(&f, 'f');

    /* Display their new values. */

    printf("\n % d", i);
    printf("\n % ld", l);
    printf("\n % f", f);
    printf("\n % lf\n", d);

    return 0;
}

void half(void *pval, char type)
{
    /* Depending on the value of type, cast the */
    /* pointer val appropriately and divide by 2. */

    switch (type)
    {
        case 'i':
        {
            *((int *)pval) /= 2;
            break;
        }

        case 'l':
        {
            *((long *)pval) /= 2;
            break;
        }

        case 'f':
        {
            *((float *)pval) /= 2;
            break;
        }

        case 'd':
        {
            *((double *)pval) /= 2;
            break;
        }
    }
}