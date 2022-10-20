//header file to define structs to store directories and values 
#define POSIX_SOURCE 200809L


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

//defining struct and type LIST 
typedef struct fileList{
    char           *stringVal;
    struct fileList    *nextVal;
} LIST;

extern LIST *newList(void); 

extern LIST *addToList(LIST *previousList, char *stringVal);

extern void printList(LIST *list);

extern LIST *traverseDirectory(char *directoryName, char *word, char *troveFileName);

extern uint32_t hashValue(char *string);

extern void addToHash(char *string);

extern void printHashTable(void);

extern int buildList();

extern int buildTrove(LIST *list);

extern char findWordInTrove(char *directory, char *word);


