#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string text1 = get_string("Speler 1...");
    string text2 = get_string("Speler 2...");

    do
    {
        if (text2[0] != text1[strlen(text1) - 1])
        {
            printf("Speler 1 wint!");
            return
        }

        text1 = get_string("Speler 1...");
    }
    while (text2[0] != text1[strlen(text1) - 1]);
}
