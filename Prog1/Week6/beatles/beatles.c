// Oefening voor werken met struct

#include <stdio.h>
#include <cs50.h>

#define AMOUNT 4

struct musician {
    string name;
    string instrument;
    int year_born;
};

void print_musician(struct musician m);

int main()
{
    // Set the fields to the appropriate values
    // This is most simplest approach to set field values in struct
    struct musician beatles[AMOUNT] =
    {
        {"John","guitar, vocals", 1940},
        {"Paul", "bass, vocals", 1942},
        {"George", "guitar, vocals", 1943},
        {"Ringo", "drums", 1940}
    };



    // Call the print function on the struct and print the header
    printf("The members of The Beatles are: \n");
    for (int i = 0; i < AMOUNT; i++)
    {
        print_musician(beatles[i]);
    }
}


/*******
* Print function to print structs
*/
void print_musician(struct musician m)
{
    // Print each member for themselves in nice formatting
    printf("Name: %6c%s\n", ' ', m.name);
    printf("Instrument: %s\n", m.instrument);
    printf("Born: %6c%i\n\n", ' ', m.year_born);
}
