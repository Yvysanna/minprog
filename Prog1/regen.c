/**********************************************************
* regen.c
*
* M. Westerman
* Programmeren 1
*
* Dit bestand is onderdeel van een reeks
* tentamenoefeningen binnen het vak
* programmeren 1.
**********************************************************/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int rain = 0, days = 0, input;

    // prompt for amount untill input equals 999
    do
    {
        input = get_int("Hoeveel: ");

        // if first input is 999 return error
        if (input == 999 && days == 0)
        {
            printf("Dat kan niet\n");
            return 1;
        }
        else if (input != 999)
        {
            // add value to variables
            rain += input;
            days++;
        }
    }
    while (input != 999);

    // calculate and print mean rain
    printf("Gemiddeld %.1f millimeter\n",
        rain / (days * 1.0));
}
