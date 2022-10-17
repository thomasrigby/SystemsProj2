#include <trove.h>

int buildTroveFile(char *trovefile, char *directoryName){
    FILE *fp;

    //fopen with "w" will create a new file if it doesn't exist and will overwrite the file if it does exist
    fp = fopen(trovefile, "w");
    if(fp == NULL){
        printf("Error opening file %s", trovefile);
        return 1;
    }
    traverseDirectory(directoryName);
    fclose(fp);
    return 0;
}