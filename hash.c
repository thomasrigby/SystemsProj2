#include "trove.h"

#define MAX      40 //arbitrary amount, will change (40 just to show values)

LIST *hashtable[MAX]; //defining hashtable as global variable with max size

//converts string value to hash values
uint32_t hashValue(char *address)
{
    uint32_t hash = 0;

    while(*address != '\0'){
        hash = hash*33 + *address;
        address++; 
    }
    return hash;
}

//adds strings as hash values to hashTable
void addToHash(char *address)
{
    int h = hashValue(address) %MAX;

    hashtable[h] = addToList(hashtable[h], address);
}

//prints hash table values atm for debugging reasons
void printHashTable(void)
{
        for (int i = 0; i <MAX; i++){
            printf("\n---[%i]---\n", i);
            printList(hashtable[i]); 
        }
}


//add more arguyments 
//create an array to store filenames and directories
//directory traverse 
//re-read documentation 