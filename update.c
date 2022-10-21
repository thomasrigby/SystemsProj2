#include "trove.h"

int updateTroveFile(LIST *list, char* trovefile, int length){
    //Send a duplicate to the remove function

    LIST *list2 = malloc(sizeof(LIST));
    list2 = list;
    removeFileFromTrove(list2, trovefile);


    //now since we have all the values ingested into the hash table, we can now start adding the files
    //to the trove file

    //open the trove file
    FILE *troveFile = fopen(trovefile, "a");
    if(troveFile == NULL){
        printf("Error opening trove file");
        exit(1);
    }
    //open the tempfile
    FILE *tempFile = fopen("tempFile.txt", "r");
    if(tempFile == NULL){
        printf("Error opening tempfile");
        exit(1);
    }
    //read the tempfile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    //Read the tempfile line by line
    char *hashmap = malloc(sizeof(char) * 10000);
    strcat(hashmap, "hashtable:");

    while((read = getline(&line, &len, tempFile)) != -1){
        // Remove the newline character
        line[strlen(line) - 1] = '\0';
        FILE *file = fopen(line, "r");
        if (file == NULL)
        {
            printf("Error opening file %s\n", line);
            exit(1);
        }
        // Read the file
        char *fileLine = NULL;
        size_t fileLen = 0;
        ssize_t fileRead;
        char *string;
        string = malloc(sizeof(char) * 10000);
        strcpy(string, line);
        // Read the file and get each word
        while ((fileRead = getline(&fileLine, &fileLen, file)) != -1)
        {
            // Remove the newline character
            fileLine[strlen(fileLine)] = '\0';
            // Get the word
            char *word = strtok(fileLine, " ");
            // While there are still words
            while (word != NULL)
            {
                // If the word is the correct length
                if (strlen(word) == length)
                {
                    addToHash(word);
                    char *hashString = malloc(sizeof(char) * 10);
                    sprintf(hashString, "%d", (hashValue(word) % MAX));
                    if (strstr(string, hashString) == NULL)
                    {
                        strcat(string, " ");
                        strcat(string, hashString);
                    }
                    if (strstr(hashmap, hashString) == NULL)
                    {
                        strcat(hashmap, " {");
                        strcat(hashmap, hashString);
                        strcat(hashmap, " ");
                        strcat(hashmap, word);
                        strcat(hashmap, "}");
                    }
                }
                // Get the next word
                word = strtok(NULL, " ");
            }
        }
        fprintf(newTroveFile, "%s\n", string);
        // Close the file
        fclose(file);
    }

    // Close the tempfile
    fclose(tempFile);
    // Close the troveFile
    fprintf(newTroveFile, "%s", hashmap);
    fclose(newTroveFile);

    // Delete the tempfile
    remove("tempFile.txt");

    return 0;
}