#include "trove.h"

int updateTroveFile(LIST *list, char* trovefile, int length){
    //Send a duplicate to the remove function
    LIST *list2 = malloc(sizeof(LIST));
    list2 = list;
    removeFileFromTrove(list2, trovefile);
    //open the trove file
    FILE *troveFile = fopen(trovefile, "a");
    if(troveFile == NULL){
        printf("Error opening trove file");
        exit(1);
    }
    //open the tempfile
    printf("Opening tempfile\n");
    FILE *tempFile = fopen("tempFile.txt", "r");
    if(tempFile == NULL){
        printf("Error opening tempfile");
        exit(1);
    }
    //read the tempfile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
    char *hashmap = malloc(sizeof(char) * 100000);
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
            fileLine[strlen(fileLine)] = '\0';
            char *word = strtok(fileLine, " ");
            while (word != NULL)
            {
                if (strlen(word) == length)
                {
                    addToHash(word);
                }
                // Get the next word
                word = strtok(NULL, " ");
            }
        }
        //Get all the words from the hash table and add them to the trove file

        for(int i = 0; i < MAX; i++){
            if(hashtable[i] != NULL){
                strcat(hashmap, "{");
                //turn uint32_t to string
                char *key = malloc(sizeof(char) * 100);
                sprintf(key, "%d", hashValue(hashtable[i]->stringVal));
                strcat(hashmap, key);
                strcat(hashmap, " ");
                strcat(hashmap, hashtable[i]->stringVal);
            }
        }

        fprintf(troveFile, "%s\n", string);
        // Close the file
        fclose(file);
    }


    // Close the tempfile
    fclose(tempFile);
    // Close the troveFile
    fprintf(troveFile, "%s", hashmap);
    fclose(troveFile);

    // Delete the tempfile
    remove("tempFile.txt");

    return 0;
}