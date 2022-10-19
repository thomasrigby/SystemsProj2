#include "trove.h"

LIST *newList(void)
{
    return NULL;
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
    while(list != NULL)
    {
        printf("%s\n", list->stringVal);
        list = list->nextVal;
    }
}




