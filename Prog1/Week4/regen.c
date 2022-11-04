#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int regen = 0, totaal = 0, dagen = 0;
    while (regen != 999)
    {
        regen = get_int("Hoeveelheid: ");
        dagen++;

        if (regen == 999 && dagen == 1)
        {
            printf("Dat kan niet");
            return 1;
        }
        else if (regen == 999)
        {
            dagen--;
        }
        else
        {
            totaal += regen;
        }
    }

    int result = totaal / dagen;
    printf("Gemiddeld %i millimeter", result);
    return 0;
}
