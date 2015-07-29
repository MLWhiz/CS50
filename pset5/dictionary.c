/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */

int hashvalue(const char* a);

int word_count=0;
char word[LENGTH+1];
typedef struct node
{
    char* word;
    struct node* next;
}
node;

//each element in htable will contain an address to a node
node* htable[HT_SIZE];

bool check(const char* word)
{
    int hv = hashvalue(word);
    node* ptr = malloc(sizeof(node)); 
    ptr = htable[hv]->next;
    while(ptr!=NULL)
    {
        //if ( (int)toupper(ptr->word[1])<(int)toupper(word[1]))
        //    return false;
        if (strcasecmp(ptr->word,word)==0)
        {
            return true;
        }

        else
        {
            ptr = ptr->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Open the given file location
    FILE* inptr = fopen(dictionary,"r");
    // create a keeper for the word which is a character array of length Large
    for (int i = 0; i < HT_SIZE; i++) 
    {
        htable[i] = malloc(sizeof(node));
    }

    if (inptr == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    
    while (fscanf(inptr,"%s\n",word) != EOF)
    {
    
        node* newword = malloc(sizeof(node));
        newword->word = malloc(strlen(word)+1);
        strcpy(newword->word,word);
        newword->next = NULL;
        int hv = hashvalue(word);
        word_count++;
        if (htable[hv]==NULL)
        {   
            htable[hv]->next = newword;
        }
        else
        {
            node* nodenext = malloc(sizeof(node));
            nodenext = htable[hv]->next;
            htable[hv]->next = newword;
            newword->next = nodenext;
        }    
    }
    return true;

}

/**
 Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return word_count;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{   
    node* pnode;
    node* ptr; 
    for(int i=0;i<HT_SIZE;i++)
    {
       ptr = htable[i];
       while(ptr!=NULL)
        {   
            pnode=ptr; 
            ptr = ptr->next;
            free(pnode);
        }
    }
    free(ptr);
    return true;
}


int hashvalue(const char* a)
{
    int x =  a[0];
    int y =  a[1];
    int hash = 0 ;
    
    if (x > 64 && x < 91 )
    {
        x = x + 32;
    }
    if (y > 64 && y < 91 )
    {
        y =y+32;
        
    }
    hash = (x*y)%(HT_SIZE);
    return hash;      
}

/*
int hashvalue(const char* a)
{
    char x =  a[0];
    int hash = 0 ;
    
    if (x > 64 && x < 91 )
    {
        x = x + 32;
    }
    hash = x%(HT_SIZE);
    return hash;      
}
*/
/*
int hashvalue(const char* a)
{
    int len = strlen(a);
    int hash = 0 ;
    hash = len%(HT_SIZE);
    return hash;      
}
*/
/*
int hashvalue(const char* a)
{
    int len = strlen(a);
    int hash = 0 ;
    for (int i =0; i<len;i++)
    {   
        int x =  a[i];
        if (x > 64 && x < 91 )
        {
            x = x + 32;
        }
        hash = hash + x;
    }
    return hash;      
}
*/
/* DOESNT WORK WHY??????
int hashvalue(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HT_SIZE;
}
*/
