#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

    // Get Float to handle dollars and cents
    float change;
    do {
        change = get_float("Change owed: "); 
    } while (change <= 0);

    int cents = round(change * 100);
    int quarter = 25; int dime = 10; int nickle = 5; int penny = 1; int answer = 0;
    
    while (cents >= penny){
        if (cents >= quarter){
            cents -= quarter;
            answer++;
        } 
        else if (cents >= dime){
            cents -= dime;
            answer++;
        } 
        else if (cents >= nickle){
            cents -= nickle;
            answer++;
        } 
        else if (cents >= penny){
            cents -= penny;
            answer++;
        }
    }

    printf("%i%s", answer, "\n");

}
