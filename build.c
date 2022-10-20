#include "trove.h"


//Build trove will take in a filename for the troveFile, then will take in
//a list of files to be added to the troveFile, the length of the words.

int buildTrove(LIST *list, char *troveFile, int length){

    //Traverse directory of each file in the list, and store it in the troveFile
    FILE *troveFile = fopen(troveFile, "w");

    if(troveFile == NULL){
        printf("Error opening trove file");
        exit(1);
    }

    //Go through each file in the list, and add it to another list
    LIST *extensiveFileList = newList();
    while(list != NULL){
        //traverseDirectory returns a list of all the files in a directory
        extensiveFileList = traverseDirectory(list->stringVal, extensiveFileList);
        list = list->nextVal;
    }

    //Build a hashtable first
    LIST *newHashTable[65536];
    
    //Now that the hashtable is built, we go through each file to get each word
    //We need a string with format /Filename : 1, 2, 3, with each integer representing the hash value of the word
    //We then add this string to the troveFile on an empty line at the bottom.
    while(extensiveFileList != NULL){
        //Open the file
        FILE *file = fopen(extensiveFileList->stringVal, "r");
        if(file == NULL){
            printf("Error opening file %s", extensiveFileList->stringVal);
            exit(1);
        }
        char *filename = extensiveFileList->stringVal;

        char *string = filename;
        char *word = malloc(sizeof(char) * length);

        while(fscanf(file, "%s", word) != EOF){
            //make sure the word is not too long
            if(strlen(word) < length){
                //Add word to hashtable
                addToHash(word);
                //Append hashed value to string
                char *hash = hashValue(word);
                strcat(string, hash);
            }
        }
        //Append string to troveFile
        fprintf(troveFile, ",%s", string);
        extensiveFileList = extensiveFileList->nextVal;

        //Close current file
        fclose(file);

    }


}

