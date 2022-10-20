#include "trove.h"


//Recursive function to traverse through all child directories of directory given and prints all files in the directory
LIST *traverseDirectory(char *directoryName){
    DIR *directory;
    //char *defaultTroveF = "/tmp/trove";
    struct dirent *directoryEntry;
    struct stat fileStat;
    char path[1024];
    LIST *list = newList();
   
    directory = opendir(directoryName);
    if(directory == NULL){
        printf("Error opening directory %s\n", directoryName);
        exit(1);
    }

    while((directoryEntry = readdir(directory)) != NULL){
        if(strcmp(directoryEntry->d_name, ".") == 0 || strcmp(directoryEntry->d_name, "..") == 0){
            continue;
        }
        sprintf(path, "%s/%s", directoryName, directoryEntry->d_name);
        if(stat(path, &fileStat) < 0){
            printf("Error getting file stats for %s", path);
            continue;
        }
        if(S_ISDIR(fileStat.st_mode)){
            traverseDirectory(path);
        }
        else{
            //lets make a list and add the files to the list
            addToList(list, path);
        }
    }
    closedir(directory);
    return list;
} 

    


