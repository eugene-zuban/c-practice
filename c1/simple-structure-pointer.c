#include <stdio.h>

int main(void)
{
    struct date {
        int month;
        int day;
        int year;
    };

    struct date today, *datePtr = &today;

    datePtr->month = 8;
    datePtr->day = 16;
    datePtr->year = 2017;

    printf("Today's date is %i/%i/%i\n", datePtr->month, datePtr->day, datePtr->year % 100);

    return 0;
}
