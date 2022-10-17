//header file to define structs to store directories and values 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>


extern int traverseDirectory(char *directoryName);


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


