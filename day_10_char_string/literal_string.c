#include <stdio.h>

int main()
{
    // A literal string evaluates as a ptr to a string.
    // I.e. "hello world" is a ptr!
    // Therefore, puts() can be used to display literal strings.
    puts("hello world");

    return 0;
}