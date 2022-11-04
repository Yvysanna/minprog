#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Check if 0 accepted
// Check if 0a accepted

// Implement a program that encrypts messages using Caesar's cipher, per the below.


// Command encryption factor non-negative int
// Assert error for wrong argument
// Calculate letter + encryption factor
// If factor causes letter > 26, work with modulo
void change(char* text, int offset) {
    for (int i = 0, l = strlen(text); i < l; i++){
        if (isupper(text[i])) {
            text[i] = (char) (65 + (((int)text[i] - 65) + offset) % 26);
        }
        else if (islower(text[i])) {
            text[i] = (char) (97 + (((int)text[i] - 97) + offset) % 26);
        }
    }
}

// Checks if every char in a string is numeric
int is_num(string text){
    for (int i = 0, l = strlen(text); i < l; i++){
        if (!isdigit(text[i])){
            return 1;
        }
    }
    return 0;
}

int main (int argc, char** argv) {

    // If not correct amount of arguments, raise error and exit
    if (argc != 2) {
        printf("Usage: ./caesar key > 0\n");
        exit(1);
    }

    // Convert string to digit; if letters in string, value would be 0, so check if digit or letter
    else if((atoi(argv[1]) >= 0 && is_num(argv[1]) == 0)) {

        // Prompt for user input
        string text = get_string("plaintext:  ");
        int offset = atoi(argv[1]);

        change(text, offset);
        printf("ciphertext: %s\n", text);
        exit(0);
    }
    else {
        printf("ERROR\n");
        exit(1);
    }
}

