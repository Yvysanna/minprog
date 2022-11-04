// Calculates how many bottles of water are used for n minutes of showering

#include <stdio.h>
#include <cs50.h>

int main(void){
    int minutes;
    do {
        minutes = get_int("Minutes: ");
    } while (minutes < 0);

    int bottles = (192 * minutes) / 16;

    printf("Bottles: %d\n", bottles);
}