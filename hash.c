#include "trove.h"
//defining hashtable as global variable with max size

int MAX = 40;
LIST *hashtable[40];

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


//Store each hash table key and value in trove file so that it can be regurgitated later
//Then build the hash table by reading trove file
int buildHash(FILE *fp, LIST *list){
    if (fp == NULL){
        perror ("Error opening file"); 
        return EXIT_FAILURE;  
    } 

    //We get the trove file pointer, and the list containing the key-value pairs,
    //we then append the key:value pairs to the beginning of the trove file, 
    //and if the line its being appended to is longer than 200 characters, we 
    //go down and make a new line to append it to. We want all the hashtable values at
    //the top of the file and not going past 200 characters per line.

    struct stat st;
    if(fstat(fileno(fp), &st) !=0){
        perror("fstat"); 
        exit(EXIT_FAILURE);
    }
    #define MAXLINESIZE (200)
    LIST *tmp = list;
    int file_length = st.st_size;

    //This is where we traverse the list and write the key/value pairs to the file
    if(file_length == 0){
        while(tmp != NULL){
            if(fprintf(fp, "{%s}", tmp->stringVal) > 200){
                fprintf(fp, "/n{%s}", tmp->stringVal);
            } else {
                fprintf(fp, "{%s}", tmp->stringVal);
            } 
        }
    } else{
        while(tmp != NULL){
            if(fprintf(fp, "{%s}", tmp->stringVal) > 200){
                fprintf(fp, "/n{%s}", tmp->stringVal);
            } else {
                fprintf(fp, "{%s}", tmp->stringVal);
            } 
        }
    }
    
    //Clear the buffer when finished writing
    fflush(stdout);
    return EXIT_SUCCESS;
}

