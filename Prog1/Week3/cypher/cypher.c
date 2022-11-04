// Problems: do not convert non-alpha

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define MAX 25
#define UP_A 65
#define LOW_A 97


char cypher_lower(char letter){
    return tolower((char) (int) letter + MAX - (((int) letter - UP_A) * 2));
}

char cypher_upper(char letter){
    return toupper((char) (int) letter + 25 - (((int) letter - 97) * 2));
}

int is_valid(string arg){
    if (arg[0] == '-' && arg[1] == 'l'){
        return 1;
    }
    return 0;
}

int main(int argc, string argv[]){

    // Flag for command line arg
    int lower = 0;
    if (argc > 1){
        lower = is_valid(argv[1]);

        // If arg given but it's invalid, stop!
        if(!lower){
            return 1;
        }
    }

    // Get input
    string ptext = get_string("plaintext:  ");
    string ctext = ptext;

    // Iterate over each char and change it accordingly
    for (int i = 0, len = strlen(ptext); i < len; i++){

        // ALWAYS CHECK IF SPACES OR OTHER SYMBOLS
        if (isalpha(ptext[i])){

            // Enforce lowercase or change lower to upper or upper to lower
            if (lower){
                ctext[i] = cypher_lower(toupper(ptext[i]));
            }
            else if (isupper(ptext[i])){
                ctext[i] = cypher_lower(ptext[i]);
            }
            else if (islower(ptext[i])){
                ctext[i] = cypher_upper(ptext[i]);
            }
        }


    }
    printf("cyphertext: %s\n", ctext);

    // Output cyphertext followed by plaintext
    // Print newline after cyphertext
    // return 0 from main

    return 0;
}
