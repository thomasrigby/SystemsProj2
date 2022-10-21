#include "trove.h"

LIST *newList(void){
    LIST *list = malloc(sizeof(LIST));
    list->stringVal = NULL;
    list->nextVal = NULL;
    return list;
}

//adds string values to list 
//through memory allocation, and pointer access 
LIST *addToList(LIST *previousList, char *stringVal)
{
    LIST *newlist = malloc(sizeof(LIST));

    //newlist adding value of string as a duplicate copy
    newlist->stringVal = strdup(stringVal);

    newlist->nextVal = previousList; 

    return newlist; 
}

//function to print the list 
void printList(LIST *list){
    while(list != NULL){
        printf("List Value: %s\n", list->stringVal);
        list = list->nextVal;
    }
}

LIST *getToHead(LIST *list){
    while(list->nextVal != NULL){
        list = list->nextVal;
    }
    return list;
}



