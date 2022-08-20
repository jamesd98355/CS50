// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_number = hash(word);

    // check this linked list for word
    if (table[hash_number] == NULL) // empty linked list
    {
        return false;
    }
    // linked list has at least one node
    node *cursor;
    do
    {
        // traverse linked list and compare values to word
        cursor = table[hash_number]; // cursor is set to first node in the list

        if (strcasecmp(cursor->word, word)) //compare strings case insensitively
        {
            return true;
        } else // not match current node
        {
            cursor = cursor->next;
        }
    } while (cursor->next != NULL); //reached end of list
    return false; // hasn't found word in the hash specific linked list
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char *word[LENGTH];

    // TODO
    //open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if(!dict)
    {
        printf("Could not read file!\n");
        return 1;
    }

    //read strings one at a time
    while (fscanf(dict, "%s", *word) != EOF) // scan until fscanf reaches end of file
    {
        //create a new node for each word
        node *n = malloc(sizeof(node)); //enough memory for the max length word + \0
        if(!n) // if malloc returns null
        {
            printf("Not enough memory for malloc.\n");
            return 1;
        }
        //set values for new node
        strcpy(n->word, *word);
        n->next = NULL;

        //hash word to obtain a hash value

        int hash_number = hash(*word);
        //insert node into hash table at that location

        //if linked list empty make current node the first node
        if (table[hash_number] == NULL)
        {
            table[hash_number] = n;
        }else //already a node
        {
            //point node next to first node and make node the first in the list
            n->next = table[hash_number];
            table[hash_number] = n;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
