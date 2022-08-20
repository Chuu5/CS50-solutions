// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "strings.h"
#include <stdlib.h>
#include "dictionary.h"
#include "string.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
// Initializing N at the same size of the dictionary
const unsigned int N = 140000;

// Hash table
node *table[N];
int number_words = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    node *tableWord = table[index];


    while (tableWord != NULL)
    {
        if (strcasecmp(tableWord->word, word) == 0)
        {
            return true;
        }
        // looping until verify all the words in the index
        tableWord = tableWord->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int count = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        count += tolower(word[i]);
    }

    // returning the specific index of the word
    return count % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }

        // coping word in the newNode
        strcpy(newNode->word, word);
        printf("%s\n", newNode->word);

        int index = hash(word);

        // verifying if some words is already in this position
        if (table[index] == NULL)
        {
            newNode->next = NULL;
            table[index] = newNode;
        }
        else
        {
            newNode->next = table[index];
            table[index] = newNode;
        }

        number_words++;
    }

    // close file
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return number_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;

            free(tmp);
        }


    }

    return true;
}
