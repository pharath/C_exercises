/* Demonstrates the fgets() function. */

#include <stdio.h>

#define MAXLEN 10

int main( void )
{
    char buffer[MAXLEN];

    puts("Enter text a line at a time; enter a blank to exit.");

    while (1)
    {
        fgets(buffer, MAXLEN, stdin);

        // if exactly 0, 9, 18, 27, etc. chars are entered the program will exit because
        // then the last call to fgets() will read '\n' from the buffer and the
        // following if condition evaluates to true
        if (buffer[0] == '\n')
            break;

        puts(buffer);
    }
    return 0;
}
