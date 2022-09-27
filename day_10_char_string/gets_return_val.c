/* Demonstrates using the gets() return value. */

/* IMPORTANT: */
/* Compile with: gcc -std=c99 gets_return_val.c -o gets_return_val */

/* https://stackoverflow.com/questions/34031514/implicit-declaration-of-gets */
/* The function gets() has been removed from C11 standard, so compile with C99. */
/* That means there's no longer a prototype for gets() in <stdio.h>. */
/* gets() used to be in <stdio.h>. */

#include <stdio.h>

/* Declare a character array to hold input, and a pointer. */

char input[257], *ptr;

int main( void )
{
    /* Display instructions. */

    puts("Enter text a line at a time, then press Enter.");
    puts("Enter a blank line when done.");

    /* Loop as long as input is not a blank line. */

    while ( *(ptr = gets(input)) != NULL)
    // while ( *(ptr = fgets(input, 20, stdin)) != '\n')
        printf("You entered %s\n", input);

    puts("Thank you and good-bye\n");

    return 0;
}
