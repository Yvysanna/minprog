#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int oppervlakte(int lengte, int breedte);

int main(void)
{
    int lengte1 = get_int("Lengte 1: ");
    int breedte1 = get_int("Breedte 1: ");
    int lengte2 = get_int("Lengte 2: ");
    int breedte2 = get_int("Breedte 2: ");

    char invoer = get_char(\
        "Wil je de oppervlakte van rechthoek (1) of (2), of de (S)om of het (V)erschil weten? "\
    );

    // Bereken en print het resultaat voor de gevraagde berekening, bij ongeldige invoer print error
    if (invoer == '1')
    {
        printf("%i\n", oppervlakte(lengte1, breedte1));
        return 0;
    }
    else if (invoer == '2')
    {
        printf("%i\n", oppervlakte(lengte2, breedte2));
        return 0;
    }
    else if (invoer == 'V')
    {
        printf("%i\n", oppervlakte(lengte1, breedte1) - oppervlakte(lengte2, breedte2));
        return 0;
    }
    else if (invoer == 'S')
    {
        printf("%i\n", oppervlakte(lengte1, breedte1) + oppervlakte(lengte2, breedte2));
        return 0;
    }
    else
    {
        printf("Dit is geen geldige keuze\n");
        return 0;
    }
    return 0;
}

/****************
* Berekend de oppervlakte van een rechthoek door zijn lengte en breedte
*/
int oppervlakte(int lengte, int breedte)
{
    return lengte * breedte;
}
