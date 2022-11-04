#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>


int main (void)
{
    int c = atoi("C"), f = atoi("F");
    // Eendtemperatur C of F
    string eendtemp;
    do
    {
        eendtemp = get_string("Welke eenheid van temperatuur (C of F)? ");
    }
    while ((strcmp(eendtemp, "C") != 0) && (strcmp(eendtemp, "F") != 0));


    // Voor Celsius, reken met celsius formula
    if ((strcmp(eendtemp, "C") == 0))
    {
        int begin = get_int("Wat is de begintemperatuur? ");
        int end = get_int("Wat is de eindtemperatuur? ");
        int stap;
        do
        {
            stap = get_int("Wat is de stapgrootte? ");
        }
        while (stap < 1);

        // Print first line outside loop
        printf("  C |   F\n");

        // Calculate and print temperature for each step, starting at begin, updating with step, ending with end
        for (int C = begin; C <= end; C = C + stap)
        {
            int F = (18 * C + 320) / 10;
            printf("%3d | %3d\n", C, F);

        }
    }

    // Voor Fahrenheit
    if ((strcmp(eendtemp, "F") == 0))
    {
        int begin = get_int("Wat is de begintemperatuur? ");
        int end = get_int("Wat is de eindtemperatuur? ");
        int stap;
        do
        {
            stap = get_int("Wat is de stapgrootte? ");
        }
        while (stap < 1);

        // First line print statement
        printf("  F |   C\n");

        // Calculate and print temperature for each step, starting at begin, updating with step, ending with end
        for (int F = begin; F <= end; F = F + stap)
        {
            int C = (10 * F - 320) / 18;
            printf("%3d | %3d\n", F, C);

        }
    }
}