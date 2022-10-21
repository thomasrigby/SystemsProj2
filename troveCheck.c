#include "trove.h"

//structure of directory contents (unsure if we need this)
// int buildList()
// {
//     DIR *f; 
//     struct dirent *trovefile;
//     f = opendir(".");

//     if(f == NULL)
//     {
//         printf("Error opening directory!\n");
//     }
    
//     LIST *filelist = malloc(sizeof(LIST));
//     while((trovefile = readdir(f)) != NULL)
//     { 
//        filelist = addToList(filelist, trovefile->d_name); 
//     }
   
//     printList(filelist);
//     //findWordInList(filelist, &argv[3]);
//    return 0;
// }

void findTrove(char *pathname)
{
    //given the pathname (if one not provided, /tmp/trove), use realpath to see if it exists 
    //if it does, (for now), print something
    //if it doesn't print failure 
    //String concatention time 
   
    char buf[PATH_MAX+1];
    char *path = realpath(pathname, buf);
    if(path != NULL)
    {
        printf("The complete file path of trove file %s is: %s\n", pathname, buf);
        //Call printWord 
    }
    else{
        printf("Trove file does not exist\n");
    }
   
}
