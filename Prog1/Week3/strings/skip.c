// Input "Great, gifts! yields Get it!"

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string input = get_string("Type something: ");
    for (int i = 0, length=strlen(input); i < length; i++) {
        if (i % 2 == 0){
            printf("%c", input[i]);
        }
    }
    printf("\n");
}