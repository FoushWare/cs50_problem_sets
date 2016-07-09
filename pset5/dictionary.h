/**
 * dictionary.h
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
//prototy of hash_function
int hash_function(const char*key);
//prototype of appening function to append words of dictionary to hashtable
void append(char*appended_word,int index);
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);
//make nodes(billard ball) to put it in the bucket(array of pointer)

typedef struct node
{
  char* word;
  struct node*next;
}node;

//making the buckets (array of pointer)
node*buckets[26];

//dicionary words


#endif // DICTIONARY_H