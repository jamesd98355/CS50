// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 200;

// Hash table
node *table[N];

//variable to count number of words as you input them into hashtable
int total_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_number = hash(word);
    node *cursor = table[hash_number]; // cursor is set to first node in the list

    // check this linked list for word
    if (table[hash_number] == NULL) // empty linked list
    {
        return false;
    }

    // linked list has at least one node
    while (cursor != NULL) //reached end of list
    {
        // traverse linked list and compare values to word
        if (strcasecmp(cursor->word, word) == 0) //compare strings case insensitively
        {
            return true;
        } else // not match current node
        {
            cursor = cursor->next;
        }
    }
    return false; // hasn't found word in the hash specific linked list
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // add first 3 letters together then mod to array size
    int sum_of_first_three_letters;
    sum_of_first_three_letters = word[0] + word[1] + word[2];
    //return only numbers 0 to 100
    return sum_of_first_three_letters % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char word[LENGTH];

    // TODO
    //open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if(dict == NULL)
    {
        printf("Could not read file!\n");
        return false;
    }

    //read strings one at a time
    while (fscanf(dict, "%s", word) != EOF) // scan until fscanf reaches end of file
    {
        //create a new node for each word
        node *n = malloc(sizeof(node)); // create memory for new node
        if(n == NULL) // if malloc returns null
        {
            printf("Not enough memory for malloc.\n");
            return false;
        }
        //set values for new node
        strcpy(n->word, word);
        n->next = NULL;

        //hash word to obtain a hash value

        int hash_number = hash(word);
        //insert node into hash table at that location

        //if linked list empty make current node the first node
        if (table[hash_number] == NULL)
        {
            table[hash_number] = n;
        }else //already a node in linked list
        {
            //point new node.next to first node and make node the first in the list
            n->next = table[hash_number];
            table[hash_number] = n;
        }
        total_words++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    //set cursor to next node and delete temp as to not lose the next address as you delete
    node *tmp;
    node *cursor;
    // TODO
    //iterate through hashtable (array of linked lists)
    for (int i = 0; i < N; i++)
    {
        //iterate through linked lists freeing every node
        cursor = table[i];

        while(cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
