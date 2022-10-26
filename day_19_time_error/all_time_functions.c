/* Demonstrates the time functions. */

#include <stdio.h>
#include <time.h>

int main( void )
{
    time_t start, finish, now;
    struct tm *ptr;
    char *c, buf1[80];
    double duration;

    /* Record the time the program starts execution. */

    start = time(0);

    /* Record the current time, using the alternate method of */
    /* calling time(). */

    time(&now);

    /* Convert the time_t value into a type tm structure. */

    ptr = localtime(&now);

    /* Create and display a formatted string containing */
    /* the current time. */

    c = asctime(ptr);   // like ctime(), but time is passed as a type tm (whereas ctime() takes a type time_t argument)
    puts(c);
    getc(stdin);        // The program then waits for the user to press Enter (clock() does NOT measure this waiting time!)

    /* Now use the strftime() function to create several different */
    /* formatted versions of the time. */

    strftime(buf1, 80, "This is week %U of the year %Y", ptr);
    puts(buf1);
    getc(stdin);

    strftime(buf1, 80, "Today is %A, %x", ptr);
    puts(buf1);
    getc(stdin);

    strftime(buf1, 80, "It is %M minutes past hour %I.", ptr);
    puts(buf1);
    getc(stdin);

    /* Now get the current time and calculate program duration. */

    finish = time(0);
    duration = difftime(finish, start);
    printf("\nProgram execution time using time() = %f seconds.", duration);

    /* Also display program duration in hundredths of seconds */
    /* using clock(). */

    // Note: clock() measures "CPU time" which does NOT include waiting 
    //       for input/output (I/O) operations (such as getc(stdin))!
    //       See: comments in "clock_vs_time.c"
    printf("\nProgram execution time using clock() = %ld hundredths of sec.\n", clock());
    return 0;
}
