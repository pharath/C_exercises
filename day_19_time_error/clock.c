// count clock ticks elapsed since the start of the program using clock()
// i.e. "CPU time"

#include <stdio.h>
#include <time.h>

void wait ( int sec )
{
    clock_t end_wait;   // Recall, clock_t is a typedef for long
    // end_wait = clock () + sec * CLK_TCK ;    // deprecated
                                                // In POSIX.1-1996 the symbol CLK_TCK (defined in <time.h>) is
                                                // mentioned as obsolescent (= fading from general use and soon to become obsolete).
                                                // (https://man7.org/linux/man-pages/man2/times.2.html)
                                                //
                                                // Things that are "obsolete" are out of date or no longer in general use. Things that 
                                                // are "obsolescent" are fading from general use and soon to become obsolete. 
                                                // For example, the Windows XP operating system (released in 2001) is not obsolete because 
                                                // some people still use it, but it is obsolescent because it will presumably be falling 
                                                // out of use in the coming years.
    end_wait = clock () + sec * CLOCKS_PER_SEC ;    // clock(): returns the amount of time that has passed since 
                                                    //     the program started execution, in 1/100-second units ("clock ticks")
                                                    //     return type: clock_t (typedef for long)
                                                    // CLOCKS_PER_SEC: "clock ticks per second"
                                                    //     seconds = "clock() value" / CLOCKS_PER_SEC.

    while (clock() < end_wait) {}
}

int main ()
{
    printf ("Start the Wait!\n");

    wait (5);	/* Wait for 5 seconds */

    printf ("End Wait!\n");
    return 0;
}