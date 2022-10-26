// converting time: tm to time_t

#include <time.h>
#include <stdio.h>

int main(void)
{
    struct tm str_time;
    time_t time_of_day;

    str_time.tm_year = 2012-1900;   // years since 1900
    str_time.tm_mon = 6;            // months since January - [0,11]
    str_time.tm_mday = 5;           // day of the month - [1,31]
    str_time.tm_hour = 10;
    str_time.tm_min = 3;
    str_time.tm_sec = 5;
    str_time.tm_isdst = 1;          // daylight savings time ("Sommerzeit") flag
                                    // am letzten Sonntag im März vor
                                    // am letzten Sonntag im Oktober zurück
                                    // all member states of the EU observe DST

    time_of_day = mktime(&str_time);    // convert time from tm to time_t
    printf(ctime(&time_of_day));

    return 0;
}