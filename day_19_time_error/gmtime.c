// working with different timezones using gmtime()

#include <stdio.h>
#include <time.h>

#define PST (-8)    // PST = (UTC - 8), i.e. PST is eight hours behind UTC (in Los Angeles, Western US, etc.)
#define PDT (-7)    // PDT = (UTC - 7), PST when DST is being observed ("Sommerzeit")
#define CET (1)     // CET = (UTC + 1), i.e. CET is one hour ahead of UTC (in Berlin, Amsterdam, Central Europe, etc.)
#define CEST (2)    // CEST = (UTC + 2), CET when DST is being observed ("Sommerzeit")

int main ()
{
    time_t raw_time;
    struct tm *ptr_ts;

    time ( &raw_time );
    ptr_ts = gmtime ( &raw_time );  // Converts given time since epoch (a time_t value pointed to by timer) into 
                                    // calendar time, expressed in Coordinated Universal Time (UTC) in the 
                                    // struct tm format. The result is stored in static storage and a pointer 
                                    // to that static storage is returned.
                                    //
                                    // Ist "by using gmtime() to convert calendar time to UTC." im Text richtig formuliert?
                                    //
                                    // ACHTUNG: "Calendar Time" wird nicht einheitlich benutzt! Manchmal ist es 
                                    // UTC (s. comment oben), manchmal die UNIX Time (s. comment unten).
                                    //
                                    // "Calendar time is the number of seconds since epoch, which was 
                                    // at 00:00:00 January 1, 1970." 
                                    // (https://www.ibm.com/docs/de/zvm/7.1?topic=SSB27U_7.1.0/com.ibm.zvm.v710.edclv/mktime.htm)! 

    // ACHTUNG: der ptr_ts->tm_isdst flag für Sommerzeit funktioniert nur, wenn
    // man erst mktime() und dann printf(ctime()) benutzt! 
    // D.h. hier würde "ptr_ts->tm_isdst = 1;" nicht funktionieren, um auf 
    // Sommerzeit umzustellen!

    printf ("Time Los Angeles: %2d:%02d\n",
            ptr_ts->tm_hour+PDT, ptr_ts->tm_min);
    printf ("Time Amsterdam: %2d:%02d\n",
            ptr_ts->tm_hour+CEST, ptr_ts->tm_min);
    return 0;
}