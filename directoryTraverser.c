#include "trove.h"


//Recursive function to traverse through all child directories of directory given and prints all files in the directory
int traverseDirectory(char *directoryName, char *word){
    DIR *directory;
    char *troveF = "/tmp/trove";
    struct dirent *directoryEntry;
    struct stat fileStat;
    char path[1024];
    
    
    directory = opendir(directoryName);
    if(directory == NULL){
        printf("Error opening directory %s\n", directoryName);
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
            traverseDirectory(path, word);
        }
        else{
            
            //This is where we call a different function to store the words.
             //addToHash(path); //this should be called to add words to for each pathname (index in trove = hash value for word)
             //If path contains argv[/tmp/trove] then findWordCheck
            
            //printf("%s \n", path);
            if(strstr(path, troveF)){
            printf("The file %s has been found!\n", path);
            //printf("%s\n", path); 
            findWordInTrove(path, word); 
            }   
        }
    }
    closedir(directory);
    return 0;
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
    


