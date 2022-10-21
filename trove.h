//header file to define structs to store directories and values 
#define POSIX_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include <stdint.h>
#include <limits.h>


//defining struct and type LIST 
typedef struct fileList{
    char           *stringVal;
    struct fileList    *nextVal;
} LIST;

extern LIST *newList(void); 

extern LIST *addToList(LIST *previousList, char *stringVal);

extern void printList(LIST *list);

extern void traverseDirectory(char *directoryName);

extern uint32_t hashValue(char *string);

extern void addToHash(char *string);

extern void printHashTable(void);

extern int buildList();

extern char findWordInTrove(char *directory, char *word);

extern int buildTrove(LIST *list, char *troveFile, int length);

extern int removeFileFromTrove(LIST *list, char *file);

extern void ingestHashTableFromFile(char *troveFile);

extern int searchForTokenInTrove(char *token, char *troveFile);

extern int removeTokenFromStoredHashMap(char *token, char *troveFile);

extern int MAX;

extern LIST *hashtable[];