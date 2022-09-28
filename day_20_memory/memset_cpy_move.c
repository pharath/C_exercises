/* Demonstrating memset(), memcpy(), and memmove(). */

#include <stdio.h>
#include <string.h>

char message1[60] = "Four score and seven years ago ...";
char message2[60] = "abcdefghijklmnopqrstuvwxyz";
char temp[60];

void *memcpy_phth(void *dest, const void *src, size_t n);

int main( void )
{
    printf("\nmessage1[] before memset():\t%s", message1);
    memset(message1 + 5, '@', 10);
    printf("\nmessage1[] after memset():\t%s", message1);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    
    /* Some implementations of memcpy might still work for 
    overlapping inputs but you cannot count of that 
    behaviour (i.e. undefined behaviour when overlapping). 
    While memmove must allow for overlapping.
    (https://stackoverflow.com/questions/4415910/memcpy-vs-memmove) */
    
    // memcpy(temp + 4, temp + 16, 10);
    memcpy_phth(temp + 4, temp + 16, 10);
    printf("\nAfter memcpy() without overlap:\t%s", temp);
    strcpy(temp, message2);
    // memcpy(temp + 6, temp + 4, 10);  //  produces the same output as memmove()
    memcpy_phth(temp + 6, temp + 4, 10);
    printf("\nAfter memcpy() with overlap:\t%s", temp);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    memmove(temp + 4, temp + 16, 10);
    printf("\nAfter memmove() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memmove(temp + 6, temp + 4, 10);
    printf("\nAfter memmove() with overlap:\t%s\n", temp);
    return 0;
}

// produces the output as described in the book
// (from https://clc-wiki.net/wiki/C_standard_library:string.h:memcpy)
// (for glibc implementation: see https://sourceware.org/git/?p=glibc.git;a=blob;f=string/memcpy.c;h=9cf64530e7366675895a05c861689ac2831098c9;hb=HEAD)
// (for other implementations: see firefox bookmarks > CS > Coding > languages > c > C standard library (libc) > function definitions / source code > libc implementations)
void *memcpy_phth(void *dest, const void *src, size_t n)
{
    char *dp = dest;
    const char *sp = src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}