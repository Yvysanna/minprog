#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int main(void){
    string input = get_string("Type something: ");
    int count = 0;

    // For char comparison always use single quotes; single quotes imply char and not string
    for (int i = 0; input[i] != '\0'; i++){
        if (tolower(input[i]) == 'e'){
            count++;
        }
    }
    string e = "e";
    if (count > 1){
        e = "e's";
    }
    printf("The text \"%s\" contains %d %s.\n", input, count, e);
}