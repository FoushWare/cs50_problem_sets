/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"
#include<string.h>
#include <ctype.h>
#include<stdio.h>
#include <stdlib.h>
int dic_words=0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //store the coming word to organize it to compotablie with the dictionary 
    char*inword=malloc(LENGTH*sizeof(char)+1);
    int j=0;            // declare a variable as counter to count througth the char of string coming 
while(word[j]!='\0')
{
    inword[j]=tolower(word[j]);
    j++;
}
    inword[j]='\0';        // this become the lowercase word as in the dictionary 

int index=hash_function(inword);
//making a new cursor pointed to the head pointer of every bucket
node*cursor=buckets[index];
while(cursor!=NULL)
{
      //comparing the given word with the words in the bucket
     if((strcmp(cursor->word,inword))==0)   // the coming word is equal to the word in the dictionary 
     {
    free(inword);
    return true;
     }
    
   else if ((strcmp(cursor->word,inword))<0) // the word coming is short than the word in the dicionary
    {
    free(inword);
    return false;
    }
    cursor=cursor->next;
}
    free(inword);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{

//as you know you should assign all pointers to NULL
   for(int k=0;k<26;k++){
     buckets[k]=NULL;}
//reading the words from dictionary
FILE*memory=fopen(dictionary,"r");
//tempstorage to put the read word from the dictionary in it 
 char* tempword= malloc( LENGTH*sizeof(char) +1);
 
while(fscanf(memory,"%s",tempword)!=EOF)
{
 
int index=hash_function(tempword);
//fuction to append the word in the relavent bucket 
append(tempword,index);
tempword= malloc( LENGTH*sizeof(char) +1); // we create that for every new word ....yes yes we can make the origenal tempword and overwrite it 
//but this result that every node will have the latest value that overwritten because in this case all pointers will point to the same (tempword)
// because the tempword is associated with another pointers like the poiners of (the function append and hash_function )

}
 free(tempword); // to free the last unused temp block named (tempword) when reached the end of file 
//check if the file opened or not
if(ferror(memory)){
fclose(memory);
return false; }

// when the dictionary is loaded close the fie and return true 
fclose(memory);
return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    int count = 0;
    node * np;
    for (int i = 0; i < 26; i++)
    {
        np = buckets[i];
        while (np != NULL)
        {
            count++;
            np = np->next;
        }
    }
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
// unload mean free everything that you malloc 
//free every bucket and every node
   for(int i=0;i<26;i++)
   {
node*freecursor=buckets[i];
while(freecursor !=NULL)
   {

node*temp_pointer=freecursor;
freecursor=freecursor->next;
free(temp_pointer);
  }

  }   
  return true;
}


//hash_function implemention 
int hash_function(const char*key)
{
int index=toupper(key[0])-'A';
return index%26;
}
//append function to assign words of dictionary to the buckets  
void append(char*word,int index)
{
if(buckets[index]==NULL){
buckets[index]=malloc(sizeof(node));
buckets[index]->word=word;
buckets[index]->next=NULL;

}

else{
node*new_node=malloc(sizeof(node));

new_node->word=word;
new_node->next=buckets[index];// imagine that buckets[index]as the head
buckets[index]=new_node;
 
}

}




