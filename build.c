#include "trove.h"


//Build trove will take in a filename for the troveFile, then will take in
//a list of files to be added to the troveFile, the length of the words.

int buildTrove(LIST *list, char *troveFile, int length){

    //Run TraverseDirectory on each file in the list
    while(list->stringVal != NULL){
        traverseDirectory(list->stringVal);
        list = list->nextVal;
    }
    //Open the tempfile
    FILE *tempFile = fopen("tempFile.txt", "r");
    if(tempFile == NULL){
        printf("Error opening tempfile");
        exit(1);
    }
    //read the tempfile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    //Create a new troveFile
    FILE *newTroveFile = fopen(troveFile, "w+");
    if(newTroveFile == NULL){
        printf("Error opening troveFile");
        exit(1);
    }

    char *hashmap = malloc(sizeof(char) * 10000);
    strcat(hashmap, "hashtable:");

    //Read the tempfile line by line
    while((read = getline(&line, &len, tempFile)) != -1){
        //Remove the newline character
        line[strlen(line) - 1] = '\0';
        //Open the file
        FILE *file = fopen(line, "r");
        if(file == NULL){
            printf("Error opening file");
            exit(1);
        }
        //Read the file
        char *fileLine = NULL;
        size_t fileLen = 0;
        ssize_t fileRead;
        char *string = line;
        //Read the file and get each word
        while((fileRead = getline(&fileLine, &fileLen, file)) != -1){
            //Remove the newline character
            fileLine[strlen(fileLine)] = '\0';
            //Get the word
            char *word = strtok(fileLine, " ");
            //While there are still words
            while(word != NULL){
                //If the word is the correct length
                if(strlen(word) == length){
                    addToHash(word);
                    char *hashString = malloc(sizeof(char) * 10);
                    sprintf(hashString, "%d", (hashValue(word)%MAX));
                    if(strstr(string, hashString) == NULL){
                        strcat(string, " ");
                        strcat(string, hashString);
                    }
                    if(strstr(hashmap, hashString) == NULL){
                        strcat(hashmap, " {");
                        strcat(hashmap, hashString);
                        strcat(hashmap, ":");
                        strcat(hashmap, word);
                        strcat(hashmap, "}");
                    }
   
                }
                //Get the next word
                word = strtok(NULL, " ");
            }
        }
        fprintf(newTroveFile, "%s\n", string);
        //Close the file
        fclose(file);
    }

    //Close the tempfile
    fclose(tempFile);
    //Close the troveFile
    fprintf(newTroveFile, "%s", hashmap);
    fclose(newTroveFile);

    //Delete the tempfile
    remove("tempFile.txt");

    return 0;
}

