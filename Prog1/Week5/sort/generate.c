// Generates pseudorandom numbers in [0,LIMIT), one per line

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Check for correct command line input
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Read first argument (amount of numbers to be generated)
    int n = atoi(argv[1]);

    // If seed given, use as random seed, else take seed from time
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Generate as many random numbers as defined by command line
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // Success
    return 0;
}
