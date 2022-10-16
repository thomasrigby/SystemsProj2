
//creating a Hashtable that stores the valyes of the files in the filelist 
//for the trove file to traverse through and determine x/y/z
//Hashtable will contain the elements of a filelist that meet a criteria 
//Return the filename and the pathname 

#define _POSIX_C_SOURCE  200809L

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef struct _list{
    char           *s;
    struct _list   *follow;
} LIST; 

LIST *list_new(void)
{
    return NULL;
}

LIST *list_add(LIST *oldlist, char *s)
{
    LIST *newlist = malloc(sizeof(LIST));
    //check....

    newlist->s = strdup(s);
    //check....
    
    newlist->follow = oldlist; 

    return newlist; 
}
