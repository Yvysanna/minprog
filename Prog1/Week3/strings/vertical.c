// Tiny program to print string vertically

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void){
    string something = get_string("Type something: ");

    for (int i = 0, length = strlen(something); i < length; i++){
        printf("%c\n", something[i]);
    }
}