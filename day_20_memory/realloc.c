/* Using realloc() to change memory allocation. */
/* Using realloc() to increase the size of a block of dynamically allocated memory */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    char buf[80], *message;

    /* Input a string. */

    puts("Enter a line of text.");
    gets(buf);

    /* Allocate the initial block and copy the string to it. */

    message = realloc(NULL, strlen(buf)+1);
    strcpy(message, buf);

    /* Display the message. */

    puts(message);

    /* Get another string from the user. */

    puts("Enter another line of text.");
    gets(buf);

    /* Increase the allocation, then concatenate the string to it. */

    message = realloc(message,(strlen(message) + strlen(buf)+1));
    strcat(message, buf);   // return value of strcat() is a pointer to str1 (see day 17)

    /* Display the new message. */
    puts(message);
    return 0;
}
