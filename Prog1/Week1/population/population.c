// Calculate population growth of lamas over the years

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start, end;
    
    // Prompt for start size
    do {
        start = get_int("Start size: ");
    } while (start < 9);

    // Prompt for end size
    do {
        end = get_int("End size: ");
    } while (end < start);

    // Calculate number of years until we reach threshold
    int year = 0;
    while (start < end) {

        // Calculate how many newborn and dying first, before deducting and adding
        int newborn = start / 3;
        int dying = start / 4;

        // Add newborn lamas & Substract dying lamas
        start = start + newborn - dying;
        year++;
    }
    
    // Print number of years
    printf("Years: %d\n", year);
}