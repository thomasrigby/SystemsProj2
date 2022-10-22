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
#include <sys/types.h>


//defining struct and type LIST 
typedef struct fileList{
    char           *stringVal; //value for string in list
    struct fileList    *nextVal; //next value in list 
} LIST;

extern LIST *newList(void); //creates a new list of type LIST

extern LIST *addToList(LIST *previousList, char *stringVal); //adds to list 

extern void traverseDirectory(char *directoryName); //main function to traverse directories 

extern uint32_t hashValue(char *string); //function to hash a value provided 

extern void addToHash(char *string); //adds hashed value to a hashtable

extern int buildTrove(LIST *list, char *troveFile, int length); //function to build a new trove file 

extern int removeFileFromTrove(LIST *list, char *file); //removing file/s from trove file 

extern char findWordInTrove(char *directory, char *word);

extern int buildTrove(LIST *list, char *troveFile, int length);

extern int removeFileFromTrove(LIST *list, char *file);

extern void ingestHashTableFromFile(char *troveFile);

extern int searchForTokenInTrove(char *token, char *troveFile);

extern int removeTokenFromStoredHashMap(char *token, char *troveFile);

extern void findTrove(char *pathname, int word);

extern void printDashF(char *pathname, int word);

extern int updateTroveFile(LIST *list, char *troveFile, int length);

extern int replaceHashTable(char *troveFile);

extern int MAX;

extern LIST *hashtable[]; //global variable for hashtable 

