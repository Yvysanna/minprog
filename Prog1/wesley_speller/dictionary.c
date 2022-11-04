/*************************************************************************************************************************
 * dictionary.c
 *
 * Minor programmeren
 * Wesley J. Korff
 *
 * - Checks whether the words of a given text are present in a dictionary
 * - Loads the dictionary into a hashtable, and checks whether each word is present in the hashtable
 * - Also keeps track of the amount of words in the dictionary, the (amount of) misspelled words, and unloads at the end
 ************************************************************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Defines the nodes of the linked lists
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Creates as many buckets in the table as there are words in the large dictionary
// const unsigned int BUCKETS = 143091;
const unsigned int BUCKETS = 143091;
node *table[BUCKETS];

/**
 * When loading the dictionary, returns the bucket number that words of the dictionary need to be put in
 * When checking, directs each word to be checked to the right bucket of the hashtable
 */
 unsigned int hash(const char *word)
 {
     int hash_number = 0;

     // Adds the ascii values per letter of a word to hash_number, trying to spread out the hashvalues of different words as much as possible
     // The * 33 is just there to add extra variability in the final hash number
     for (int i = 0; i < strlen(word); i++)
     {
         hash_number += hash_number * 33 + tolower(word[i]);
     }
     return hash_number % BUCKETS;
 }


/**
 * Checks whether a word is present in the loaded dictionary
 */
bool check(const char *word)
{

    int index = hash(word);
    char word_check[LENGTH];

    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        strcpy(word_check, cursor->word);
        if (strcasecmp(word_check,word) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
 * Loads the words of the dictionary into the hash table
 */
bool load(const char *dictionary)
{

    // Opens the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open dictionary.\n");
        unload();
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        size();
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        int index = hash(word);

        strcpy(new_node->word, word);
        new_node->next = table[index];
        table[index] = new_node;
    }
    fclose(file);
    return true;
}

int word_counter = -1;

/**
 * Adds +1 to word_counter whenever a word is loaded into the hashtable and returns the number of words in the dictionary
 */
unsigned int size(void)
{
    word_counter++;
    return word_counter;
}

/**
 * Unloads the dictionary from memory
 */
bool unload(void)
{
    for(int index = 0; index < BUCKETS; index++)
        while (table[index] != NULL)
        {
            node *tmp = table[index]->next;
            free(table[index]);
            table[index] = tmp;
        }

    return true;
}
