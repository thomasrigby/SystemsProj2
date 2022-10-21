#include "trove.h"


//Recursive function to traverse through all child directories of directory given and store all files in a tempfile
void traverseDirectory(char *directoryName){

    if(checkIfFile(directoryName) == 1){
        //If the directory is a file, add it to the tempfile
        FILE *tempFile = fopen("tempFile.txt", "a");
        if(tempFile == NULL){
            printf("Error opening tempfile");
            exit(1);
        }

        fprintf(tempFile, "%s", directoryName);
        fprintf(tempFile, "\n");
        fclose(tempFile);
        return;
    } 

    //Open the directory
    DIR *directory = opendir(directoryName);
    if(directory == NULL){
        printf("Error opening directory");
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
    

int checkIfFile(char *fileName){
    struct stat buf;
    stat(fileName, &buf);
    return S_ISREG(buf.st_mode);
}