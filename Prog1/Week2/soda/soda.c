#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(void){

    int change = 50;
    do {
        printf("%i cents owed\n", change);
        int inserted = get_int("Insert coin: ");

        if (inserted == 25 || inserted == 10 || inserted == 5) {
            change -= inserted;
        }
    } 
    while(change > 0);

    printf("%i cents change\n", abs(change));
}