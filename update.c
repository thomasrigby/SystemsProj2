#include "trove.h"

int updateTroveFile(LIST *list, char *trovefile, int length)
{
    // Send a duplicate to the remove function
    LIST *list2 = malloc(sizeof(LIST));
    list2 = list;
    removeFileFromTrove(list2, trovefile);

    // open the trove file
    FILE *troveFile = fopen(trovefile, "a");
    if (troveFile == NULL){
        printf("Error opening trove file");
        exit(1);
    }

    // open the tempfile to read
    FILE *tempFile = fopen("tempFile.txt", "r");
    if (tempFile == NULL)
    {
        printf("Error opening tempfile");
        exit(1);
    }
    // read the tempfile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // for each line in the tempfile
    while ((read = getline(&line, &len, tempFile)) != -1){
        // Remove the newline character
        line[strlen(line) - 1] = '\0';

        // Open the file
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

        // Read the file and get each word
        while ((fileRead = getline(&fileLine, &fileLen, file)) != -1)
        {
            // Remove the newline character
            fileLine[strlen(fileLine)] = '\0';

            // Start tokenizing the line
            char *word = strtok(fileLine, " ");

            // While there are still words in the line
            while (word != NULL){
                if (strlen(word) == length){
                    // Add the word to the hashmap
                    addToHash(word);
                }
                word = strtok(NULL, " ");
            }
        }
        // Close the file
        fclose(file);
    }

    fclose(troveFile);
    fclose(tempFile);
    remove("tempFile.txt");

    replaceHashTable(trovefile);

    return 0;
}

int replaceHashTable(char *troveFile)
{
    // Open the troveFile
    FILE *trove = fopen(troveFile, "r+");
    if (trove == NULL)
    {
        printf("Error opening troveFile");
        exit(1);
    }
    // Read the troveFile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // search the trove file for the hashmap
    while ((read = getline(&line, &len, trove)) != -1){
        // get the filename from the tempfile
        char *filename = strtok(line, " ");
        // remove the newline character
        filename[strlen(filename) - 1] = '\0';
        // This is from the temp file
        if (strstr(filename, "hashtable") != NULL)
        {
            fseek(trove, -read, SEEK_CUR);
            int i;
            for (i = 0; i < read - 1; i++){
                fputc(' ', trove);
            }
            // set newline character at end of line
            fputc('\n', trove);
            fseek(trove, -read, SEEK_CUR);
        }
    }

    char *hashedString = malloc(sizeof(char) * 100000);
    strcat(hashedString, "hashtable:");

    for(int i = 0; i < MAX; i++){
        if(hashtable[i] != NULL){
            strcat(hashedString, "{");
            char *num = malloc(sizeof(char) * 10);
            sprintf(num, "%d", hashValue(hashtable[i]->stringVal));
            strcat(hashedString, num);
            strcat(hashedString, " ");
            //turn the int into a string
            strcat(hashedString, hashtable[i]->stringVal);
            strcat(hashedString, "} ");
            printf("hashedString: %s\n", hashedString);
        }
    }

    printf("THIS STRING; %s", hashedString);

    // write the hash table to the trove file

    fprintf(trove, "%s", hashedString);
    free(hashedString);
    fclose(trove);
    return 0;
}
