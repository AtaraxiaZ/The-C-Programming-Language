#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
static char monthtab1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char monthtab2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *daytab[2] = {
    monthtab1,
    monthtab2
};
static int totalday[2] = {365, 366};

int day_of_year(int year, int month, int day){
    int i, leap;
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 != 0);
    if (day > *(daytab[leap]+month) || day < 0){
        return 0;
    }
    for (i = 1; i < month; i++)
        day += *(daytab[leap] + i);
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday){
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 != 0);
    if (yearday > totalday[leap])
        return;
    for (i = 1; yearday > *(daytab[leap]+i); i++)
        yearday -= *(daytab[leap]+i);
    *pmonth = i;
    *pday = yearday;
}

int main(){
    int year = 2024;
    int month = 2;
    int day = 5;
    printf("%d\n", day_of_year(year, month, day));
    int pmonth;
    int pday;
    int yearday = 100;
    month_day(year, yearday, &pmonth, &pday);
    printf("month is %d, day is %d\n", pmonth, pday);
    return 0;
}
