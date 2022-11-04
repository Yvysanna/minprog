// Implements a dictionary's functionality

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// // Create try
// typedef struct node
// {
//     bool is_word;
//     struct node *children[27];
// }
// node;

// Node pointer tracking beginning
// node *root;

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int BUCKETS = 143091;
node *hashtable[BUCKETS];

unsigned int WORD_COUNTER = 0;

// Hashfunction here
unsigned int hash(const char *word)
{
    // Seed
    unsigned int seed = 5381;
    unsigned int c;

    while(*word != '\0')
    {
        // (seed << 4): multiply by 16
        seed = ((int) (tolower(*word)) + (seed << 6) + (seed << 16)) % BUCKETS;
        word++;
    }
    return seed;
}


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    const int index = hash(word);

    // node *cursor = hashtable[index];
    for (node *cursor = hashtable[index]; cursor != NULL; cursor = cursor->next)
    {
        // Handle case insensitivity
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Var that will hold each word from file
    char word[LENGTH + 1];

    // Try to open and read dict
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        unload();
        return false;
    }

    // Iterate over dict
    for (int c = fgetc(dict), index = 0; c != EOF; c = fgetc(dict))
    {
        // Check if char or apostrophe should belong to word
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Add char to word
            word[index] = c;
            index++;
        }
        else if (index > 0)
        {
            word[index] = '\0';

            // Create new node for word
            node *new_node = malloc(sizeof(node));

            // Check if malloc succeeds, else exit
            if (new_node == NULL)
            {
                unload();
                return false;
            }

            // Copy word into node
            strcpy(new_node->word, word);

            // Find bucket in hashtable where word should be placed in
            int bucket = hash(word);

            // Link word into hashtable with other words
            new_node->next = hashtable[bucket];
            hashtable[bucket] = new_node;

            // Increment word counter
            WORD_COUNTER++;

            // Prepare for next word
            index = 0;
        }
    }
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return WORD_COUNTER;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{

    for (int idx = 0; idx < BUCKETS; idx++)
    {
        // Iterate over every item in bucket
        while (hashtable[idx] != NULL)
        {
            node *temp = hashtable[idx];
            hashtable[idx] = hashtable[idx]->next;
            free(temp);
        }
    }

    return true;
}
