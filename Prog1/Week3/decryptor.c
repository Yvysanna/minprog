// decryptor is a program that uses frequency analysis to decryptor messages
// that were encrypted using ceasar's method

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // decryptor only accepts sentences of at least one word
    if (argc >= 2)
    {
        // count how many times each letter is used in all command-line arguments and save in 'count'
        int count[26] = {0}, x;
        for(int b = 1; b < argc; b++)
        {
            int i = 0;
            while (argv[b][i] != '\0')
            {
                // Consider characters from 'a' to 'z' only and ignore others
                if (tolower(argv[b][i]) >= 'a' && tolower(argv[b][i]) <= 'z')
                {
                    x = tolower(argv[b][i]) - 'a';
                    count[x]++;
                }
                i++;
            }
        }

        // find the most frequent letter in 'count'
        int most_frequent_letter, max_element;
        for (int c = 0, max = count[0]; c < 26; c++)
        {
            if (count[c] > max)
            {
                max = count[c];
                max_element = c;
            }
        }
        most_frequent_letter = max_element + 'a';

        // infer the key, assume most frequent letter in language is e (ascii_decimal = 101)
        int key = 101 - most_frequent_letter;


        // loop through command line arguments
        for (int d = 1; d < argc; d++)
        {
            // loop through the letters in command-line argument
            for (int j = 0, n = strlen(argv[d]); j < n; j++)
            {
                // print unchanged non-letters
                if (!isalpha(argv[d][j]))
                {
                    printf("%c", argv[d][j]);
                    //continue;
                }
                // print decrypted letter preserving input's casing
                else if (tolower(argv[d][j]) + key > 122) // ascii decimal higher than 'z'?
                {
                    printf("%c", ((char)argv[d][j] + key) - 26); // continue from 'a'
                }
                else if (tolower(argv[d][j]) + key < 97) // ascii decimal lower than 'a'?
                {
                    printf("%c", ((char)argv[d][j] + key) + 26); // continue from 'z'
                }
                else
                {
                    printf("%c", (char)argv[d][j] + key);
                }
            }

            // when multiple words are decrypted, seperate with space
            if (argc > 2)
            {
                printf(" ");
            }
        }
        // linefeed after sentence
        printf("\n");
    }
    else
    {
        printf("Usage: ./decryptor word word ...\n");
        return 1;
    }

}
