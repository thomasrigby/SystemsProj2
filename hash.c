#include "trove.h"
//defining hashtable as global variable with max size

int MAX = 10000;
LIST *hashtable[10000];

//converts string value to hash values
uint32_t hashValue(char *address){
    uint32_t hash = 0;
    while(*address != '\0'){
        hash = hash*33 + *address;
        address++;
    }
    return hash;
}

//adds strings as hash values to hashTable
void addToHash(char *address){
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

int getHashValue(char *word){
    //get index of hash table from hash value
    int h = hashValue(word) %MAX;
    //get list from hash table
    LIST *list = hashtable[h];
    //loop through list
    while(list != NULL){
        //if word is found in list return 1
        if(strcmp(list->stringVal, word) == 0){
            return 1;
        }
        list = list->nextVal;
    }
    //if word is not found in list return 0
    return -1;
}



