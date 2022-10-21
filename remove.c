#include "trove.h"

int removeFileFromTrove(LIST *list, char* troveFile){


    //Open the troveFile
    FILE *trove = fopen(troveFile, "r+");
    if(trove == NULL){
        printf("Error opening troveFile");
        exit(1);
    }
    //Read the troveFile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    //For each line in the troveFile
    //if there is a match with the file, remove it (use strstr)
    //must get through all files in list
    while(list->stringVal != NULL){
        while((read = getline(&line, &len, trove)) != -1){
            if(strstr(line, list->stringVal) != NULL){
                fseek(trove, -read, SEEK_CUR);
                int i;
                for(i = 0; i < read - 1; i++){
                    fputc(' ', trove);
                }
                //set newline character at end of line
                fputc('\n', trove);
                fseek(trove, -read, SEEK_CUR);
            }
        }
        list = list->nextVal;
    }
    fclose(trove);
    ingestHashTableFromFile(troveFile);
    return 0;
}


void ingestHashTableFromFile(char* file){
    FILE *fp = fopen(file, "r");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    //Read the file
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int hashTableFound = 0;

    while((read = getline(&line, &len, fp)) != -1){
        //look for the file containing the word hash
        if(strstr(line, "hashtable") != NULL || hashTableFound == 1){
            hashTableFound = 1;
            char *token = strtok(line, " ");
            while(token != NULL){
                if(strstr(token, "{") != NULL){
                    //we search for another instance of this token without the {
                    //and add it to the hash table
                    if(searchForTokenInTrove(token, file) == 1){
                        //add the token to the hash table
                        token = strtok(NULL, " ");
                        token[strlen(token) - 1] = '\0';
                        addToHash(token);
                    } else {
                        //set first value of token string to '{'
                        char* tempString = malloc(sizeof(char) * 10000);
                        strcat(tempString, "{");
                        strcat(tempString, token);
                        strcat(tempString, " ");
                        token = strtok(NULL, " ");
                        strcat(tempString, token);
                        printf("token: %s\n", tempString);
                        removeTokenFromStoredHashMap(tempString, file);
                        free(tempString);
                    } 
                }
                token = strtok(NULL, " ");
            }
        }
    }
    fclose(fp);
}

int searchForTokenInTrove(char *token, char *trovefile){
    for(int i = 0; i < strlen(token); i++){
        token[i] = token[i+1];
    }  
    //open the trovefile
    FILE *fp = fopen(trovefile, "r");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    //read the trovefile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while((read = getline(&line, &len, fp)) != -1){
        //look for the file containing the word hash
        if(strstr(line, "hashtable") != NULL) {
            return 0;
        }
        if(strstr(line, token) != NULL){
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int removeTokenFromStoredHashMap(char* token, char* trovefile){
    //open the trovefile
    FILE *fp = fopen(trovefile, "r+");
    if(fp == NULL){
        printf("Error opening file");
        exit(1);
    }
    //read the trovefile
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int hashTableFound = 0;
    while((read = getline(&line, &len, fp)) != -1){
        //look for the file containing the word hash
        if(strstr(line, "hashtable") != NULL || hashTableFound == 1) {
            hashTableFound = 1;
            int location = 0;
            if(strstr(line, token) != NULL){
                //find the token and remove it in line
                location = strstr(line, token) - line;
                for(int i = 0; i < strlen(token); i++){
                    line[location + i] = ' ';
                }
                fseek(fp, -read, SEEK_CUR);
                fputs(line, fp);
                fclose(fp);
                return 0;
            }
        }
    }
    fclose(fp);
    return 0;

}