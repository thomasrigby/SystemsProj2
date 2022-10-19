#include "trove.h"

//structure of directory contents (unsure if we need this)
int troveCheck(char *argv[])
{
    DIR *t; 
    struct dirent *trovefile;
    t = opendir(".");

    if(t == NULL)
    {
        printf("Error opening directory!\n");
    }
    
    LIST *filelist = malloc(sizeof(LIST));
    while((trovefile = readdir(t)) != NULL)
    { 
       filelist = addToList(filelist, trovefile->d_name); 
    }
   
    printList(filelist);
    //findWordInList(filelist, &argv[3]);
   return 0;
}