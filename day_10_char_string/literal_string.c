#include <stdio.h>

int main()
{
    // A string literal evaluates as a ptr-to-character ( char* ).
    // I.e. "hello world" is a ptr!
    // Therefore, puts() can be used to display literal strings.
    puts("hello world");

    return 0;
}