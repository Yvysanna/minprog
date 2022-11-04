#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <time.h>

void shuffle(string *array, int length)
{
    // Randomly shuffles the array into a different order
    for (int i = length - 1; i > 0; i--)
    {

        // Get random number
        int rnum = rand() % (i + 1);

        // Resort at random location with current loop location
        string temp = array[rnum];
        array[rnum] = array[i];
        array[i] = temp;
    }
}


int main(void)
{
    // Seed for random function is time
    srand(time(0));

    string names[] =
    {
      //"Katja",
      //"Hector",
      //"Kasandra",
      //"Manuja",
      "David",
      "Coen",
      "Timon",
      //"Noa",
      "Steven",
      "Finn",
      "Issa",
      "Daniel"
    };
    int alen = sizeof(names) / sizeof(string);

    // Resort the students in random order
    shuffle(names, alen);

    // Print the duos
    for(int i = 0; i < alen; i += 2)
    {
        printf("%s - %s\n", names[i], names[i + 1]);
    }
}
