/* Usage of GetSystemTime() on Windows */
/* need to install Visual Studio or something else to compile this on Windows */

/* Windows has its own SYSTEMTIME structure */
/*

typedef struct _SYSTEMTIME {
	WORD wYear;
	WORD wMonth;
	WORD wDayOfWeek;
	WORD wDay;
	WORD wHour;
	WORD wMinute;
	WORD wSecond;
	WORD wMilliseconds;
} SYSTEMTIME;

*/

#include <Windows.h>
#include <stdio.h>

void main()
{
	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	printf("Year:%d\nMonth:%d\nDate:%d\nHour:%d\nMin:%d\nSecond:% d\n"
	,str_t.wYear,str_t.wMonth,str_t.wDay
	,str_t.wHour,str_t.wMinute,str_t.wSecond);

}

/*

The output will be like:

Year: 2009
Month: 3
Day: 3
Hour: 14
Minute: 59
Seconds: 23

*/