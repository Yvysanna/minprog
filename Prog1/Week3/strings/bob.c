#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void){
    string normal = get_string("Type something: ");

    string new = normal;
    int toggle = 0;
    for (int i = 0; normal[i] != '\0'; i++){
        
        // If every other alphabetic letter, make uppercase
        if (toggle % 2 != 0 && isalpha(normal[i]) != 0){
            new[i] = toupper(new[i]);
            toggle++;
        }

        // If alphabetic, continue counting but don't do anything
        else if(isalpha(normal[i]) != 0){
            new[i] = tolower(new[i]);
            toggle++;
        }
    }
    printf("%s\n", new);
}