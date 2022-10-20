#include "trove.h"

//structure of directory contents (unsure if we need this)
int buildList()
{
    DIR *f; 
    struct dirent *trovefile;
    f = opendir(".");

    if(f == NULL)
    {
        printf("Error opening directory!\n");
    }
    
    LIST *filelist = malloc(sizeof(LIST));
    while((trovefile = readdir(f)) != NULL)
    { 
       filelist = addToList(filelist, trovefile->d_name); 
    }
   
    printList(filelist);
    //findWordInList(filelist, &argv[3]);
   return 0;
}

