#include <stdio.h>
#include <stdlib.h>
#include <string.h>

{
// Define global variables
#define START_1800 3
#define START_YEAR 1800
#define YEAR_LENGTH 365
#define FEB 2
}

#define START_YEAR 1800

// 1800 begint op 3 weekdag
#define START_1800 3

/**********
* Checks if given year is leap year
*****/
int check_leap_year(year)
{
    // Calculates leap year
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        return 1;
    }
    return 0;
}

/**********
* Count number of days from 1800 until given year
*****/
int number_of_days_1800_til_year(year)
{
    int days = 0;
    for (int i = START_YEAR; i < year; i++)
    {
        days += (365 + check_leap_year(i));
    }

    return days;
}

int main(void)
{
    number_of_days_1800_til_year(2022);
}


/**********
* Shorter code isn't automatically more efficient
*/
void efficient(void)
{
    string str = "Hello, world!";
    int length = strlen(str);
    for (int i = 0; i < length ; i++)
    {
        do something
    }
}
