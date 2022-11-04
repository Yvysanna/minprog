// Schrijf en programma dat de gebruiker vraagt om de eenheid van temperatuur: C van Celsius of F van Fahrenheit. 
// Vervolgens vraagt het programma om de begintemperatuur, de eindtemperatuur en de stapgrootte. 
// Daarna wordt een nette tabel uitgeprint, met op iedere rij de gekozen temperatuur 
// en de temperatuur in de andere eenheid.

#include <stdio.h>
#include <cs50.h> // Voor get_char
#include <string.h> // Voor strcmp
#include <ctype.h> // Voor toupper

// Calculates the fahrenheit for given celsius
void celsius(int begin, int eind, int stap) {

    // Calculate and print each step
    while (begin <= eind) {
        printf("%3d | %3d\n", begin, (18 * begin + 320) / 10);
        begin += stap;
    }
}

// Calculates the celsius for given fahrenheit
void fahrenheit(int begin, int eind, int stap) {
    while (begin <= eind) {
        printf("%3d | %3d\n", begin, (10 * begin - 320) / 18);
        begin += stap;
    }
}


int main(void){
    char eenheid;
    // Vraag de gebruiker om input, tot de gebruiker een juiste invoer geeft. Upper en lower zijn toegestaan.
    do { 
        eenheid = toupper(get_char("Welke eenheid van temperatuur (C of F)? "));
    } while (strcmp(&eenheid, "C") && strcmp(&eenheid,"F"));

    int begin = get_int("Wat is de begintemperatuur? ");
    int eind = get_int("Wat is de eindtemperatuur? ");
    
    int stap;
    do {
        stap = get_int("Wat is de stapgrootte? ");
    } while (stap <= 0);


    if (strcmp(&eenheid, "C") == 0){
        printf("%3s | %3s\n", "C","F");
        celsius(begin, eind, stap);
    } else {
        printf("%3s | %3s\n", "F","C");
        fahrenheit(begin, eind, stap);
    }
}
