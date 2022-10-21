#include "trove.h"


//Recursive function to traverse through all child directories of directory given and store all files in a tempfile
void traverseDirectory(char *directoryName){
    //Open the directory
    DIR *directory = opendir(directoryName);
    if(directory == NULL){
        printf("Error opening directory");
        exit(1);
    }
    //Read the directory
    struct dirent *directoryEntry;
    while((directoryEntry = readdir(directory)) != NULL){
        //If the entry is a directory, then we need to traverse through it
        if(directoryEntry->d_type == DT_DIR){
            //If the directory is not . or .., then we need to traverse through it
            if(strcmp(directoryEntry->d_name, ".") != 0 && strcmp(directoryEntry->d_name, "..") != 0){
                //Create a new directory name
                char *newDirectoryName = malloc(sizeof(char) * 100);
                strcpy(newDirectoryName, directoryName);
                strcat(newDirectoryName, "/");
                strcat(newDirectoryName, directoryEntry->d_name);
                //Traverse through the new directory
                traverseDirectory(newDirectoryName);
            }
        }
        //If the entry is a file, then we need to add it to the troveFile
        else if(directoryEntry->d_type == DT_REG){
            //Create a new file name
            char *newFileName = malloc(sizeof(char) * 100);
            strcpy(newFileName, directoryName);
            strcat(newFileName, "/");
            strcat(newFileName, directoryEntry->d_name);
            //Add the file to the tempfile
            FILE *tempFile = fopen("tempFile.txt", "a");
            fprintf(tempFile, "%s\n", newFileName);
            fclose(tempFile);
        }
    }
    //Close the directory
    closedir(directory);

}
    

