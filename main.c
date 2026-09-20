#include "stuff.h"
#include <_time.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Structures - Linked List

You will write two function dealing with a simple strcuture as shown below. The first function will dump the internal
values of the simpledate structure. The second will compute the day of the year similar to the sample code in Chapter 6
of the K&R book.

*/

static int day_tab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                             {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

struct simpledate {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

/* set day of year from month, day */
int day_of_year(struct simpledate *pd) {
    int res = 0;
    if (is_leap_year(pd->year)) {
        for (int month = 1; month < pd->month; month++) {
            res += day_tab[1][month];
        }
        res += pd->day;
        return res;
    } else {
        for (int month = 1; month < pd->month; month++) {
            res += day_tab[0][month];
        }
        res += pd->day;
        return res;
    }
}

/* print date from year, month, day */
void dump_date(struct simpledate *pd) {
    printf("%d/%02d/%02d\n", pd->year, pd->month, pd->day);
}

int main(void) {
    struct simpledate sd;

    sd.year  = 2023;
    sd.month = 2;
    sd.day   = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year  = 2023;
    sd.month = 9;
    sd.day   = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year  = 2024;
    sd.month = 9;
    sd.day   = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
}
