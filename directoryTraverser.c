#include "trove.h"


//Recursive function to traverse through all child directories of directory given and prints all files in the directory
LIST *traverseDirectory(char *directoryName, char *source, char *word){
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
            traverseDirectory(path, source, word);
        }
        else{
            //lets make a list and add the files to the list
            addToList(list, path);
        }
    }
    closedir(directory);
    return list;
} 

char findWordInTrove(char *directory, char *word)
{
     FILE    *textfile;
    char    line[1024];
    textfile = fopen(directory, "r");
    if(textfile == NULL)
        return 1;

    printf("The pathnames in this file with the desired word are...\n");

    while(fgets(line, 1024, textfile))
    {
    if(strstr(line, word)!=0)
        printf("%s\n",line);
    }

    fclose(textfile);
    return 0;
     //printf("%d pathnames were found containing %c\n",num, word);
    return 0;
}
    


