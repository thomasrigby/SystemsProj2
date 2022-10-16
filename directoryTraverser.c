#include "trove.h"



//Recursive function to traverse through all child directories of directory given and prints all files in the directory
int traverseDirectory(char *directoryName){
    DIR *directory;
    LIST *mylist;
    struct dirent *directoryEntry;
    struct stat fileStat;
    char path[1024];
    
    directory = opendir(directoryName);
    if(directory == NULL){
        printf("Error opening directory %s", directoryName);
        return 1;
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
            //This is where we call a different function to store the words.
            mylist = list_add(mylist, directoryEntry->d_name);
            //trovePrint(mylist);
            //printf("%s \n", path);
        }
    }

    closedir(directory);

    return 0;
}
