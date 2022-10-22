#include "trove.h"

//function to find the trove file absolute path 
void findTrove(char *pathname, int word)
{
    char buf[PATH_MAX+1]; //buffer to store pathname
    char *path = realpath(pathname, buf); //stores realpath pathname
    if(path != NULL)
    {
     printCompPath(pathname, word); 
    }   
    else{
        printf("Trove file does not exist!\n");
        }
}

//print complete path 
void printCompPath(char *pathname, int word)
{
    char *line = NULL;
    size_t length = 0; //lengthgth
    ssize_t read; //reading file provided 

    char wordAsString[10000];
    const char s[1] = " "; //space to detect when word ends
    char *token; //token to grab first word of line
    char buf[PATH_MAX+1]; //buffer to store realpath 
    sprintf(wordAsString, "%d", word%10000); //converts integer to char 

    char *lineStart = "./"; //start of path
    FILE *t = fopen(pathname, "r");
         if(t == NULL){
            printf("Error opening trove");
            exit(1);
            }
         while((read = getline(&line, &length, t)) != -1){
            //checks if hash value is in on line next to the file name 
          if((strstr(line, lineStart) && strstr(line, wordAsString))){ 
            token = strtok(line, s);
            while(token != NULL) {
                token = strtok(NULL, s);
            }
            char *path = realpath(line, buf);
            printf("%s\n", path);
         }
        }
}
