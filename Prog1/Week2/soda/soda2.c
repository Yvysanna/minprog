#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int cents = 50;

    do {
        printf("%i cents owed\n", cents);
        int coin = get_int("Insert coin: ");
        cents -= coin;
    } while(cents > 0);

    if (cents < 0) {
        cents = abs(cents);
        printf("%i cents change\n", cents);
    }
    else {
        printf("%i cents change\n", cents);
    };
}