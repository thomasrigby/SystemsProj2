#include "trove.h"

void findTrove(char *pathname, int word)
{
    //given the pathname (if one not provided, /tmp/trove), use realpath to see if it exists 
    //if it does, (for now), print something
    //if it doesn't print failure 
    //String concatention time 
    //int fword = word;
    char buf[PATH_MAX+1];
    char *path = realpath(pathname, buf);
    if(path != NULL)
    {
        // printf("The complete file path of trove file %s is: %s\n", pathname, buf);
        // printf("Searching through trove-file to print pathnames\n");
     //Call printWord 
     printDashF(pathname, word);
    }
          
    else{
        printf("Trove file does not exist!\n");
        }
    
}

void printDashF(char *pathname, int word)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char wString[10000];
    const char s[1] = " ";
    char *token;
    char buf[PATH_MAX+1];
   
    //printf("%d\n", word%10000);
    sprintf(wString, "%d", word%10000);
    //printf("%s\n", wString);
    char *lineStart = "./";
    FILE *t = fopen(pathname, "r");
         if(t == NULL){
            printf("Error opening trove");
            exit(1);
            }
         while((read = getline(&line, &len, t)) != -1){
        if((strstr(line, lineStart) && strstr(line, wString))){
            token = strtok(line, s);
            /* walk through other tokens */
            while(token != NULL) {
                token = strtok(NULL, s);
            }
             char *path = realpath(line, buf);
            printf("%s\n", path);
        }
    }
}
