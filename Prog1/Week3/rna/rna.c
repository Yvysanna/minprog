#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int valid_letter(char letter);
char make_rna(char letter);


int main(int argc, string argv[]){

    // Needs 2 args; ./rna + sequence
    if (argc != 2){
        printf("Usage: ./rna ATGC\n");
        return 1;
    }

    string sequence = argv[1], rna = sequence;

    // Iterate over each letter to check if valid letter
    for (int i = 0, len =  strlen(sequence); i < len; i++){

        // Should handle lower & uppercase
        sequence[i] = toupper(sequence[i]);

        // Should return early if letter invalid
        if (!valid_letter(sequence[i])){
            printf("Invalid DNA\n");
            return 1;
        }

        // Change letter accordingly
        rna[i] = make_rna(sequence[i]);
    }

    printf("%s\n", rna);
    return 0;
}

// Check if letter valid, return 1 if true, 0 if false
int valid_letter(char letter){
    if (letter == 'A' || letter == 'G' || letter == 'T' || letter == 'C'){
        return 1;
    }
    return 0;
}

// Returns the switched letter
char make_rna(char letter){
    if (letter == 'A'){
        return 'U';
    }
    else if (letter == 'G'){
        return 'C';
    }
    else if (letter == 'C'){
        return 'G';
    }
    else {
        return 'A';
    }
    return 'X';
}
