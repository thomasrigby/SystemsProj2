//Project 2 which creates a command line utility program 
//to build, find and compress files 
#define POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trove.h"
#include <ctype.h>
#include <dirent.h>


void trovePrint(LIST *list)
{
    while(list != NULL){
        printf("%s\n", list->s);
        list = list->follow;
    }
}

void makeFileList(char *argv[])
{
    struct dirent *files;
    DIR *file_list;
    LIST *mylist;


    file_list = opendir(".");  
    if(file_list == NULL)
    {
        printf("Unable to open directory");
        exit(0); 
    }
    else
    {
       printf("Directory opened!\n");
        while ((files = readdir(file_list)) != NULL)
                {
                    //printf("[%s]\n", files->d_name);
                    mylist = list_add(mylist, files->d_name);
                }     
                trovePrint(mylist);
                     
        }
        closedir(file_list);  
    }
//main function to receive and validate the command-line options and arguments
//command line format is  ./trove  [-f trovefile]  word 
// command line format is ./trove  [-f trovefile]  [-b  |  -r  |  -u]  [-l length]  filelist
int main(int argc, char *argv[])
{
//   if(argc < 3) //3 arguments required to find file 
//   {
//     printf("Not enough arguments to find file\n");
//     exit(0);
//   } 
//   else if (argc == 3 && strcmp(argv[1], "-f") == 0) // ensures second argument is to find file
//   {
//     if(strlen(argv[2]) < 3) //minimum length of the word is 3 characters
//     {
//         printf("Word has to be minimum of 3 characters\n");
//         exit(0);
//       }
//     else{
//     printf("Finding file to create %s file\n", argv[2]);
//   }
//   }
 
//   else if((strcmp(argv[1],"-f") == 0))
//     {
//       if((strcmp(argv[3], "-b"))==0){
//         printf("Build a file named \n");
//       }
//       if((strcmp(argv[3], "-r"))==0){
//         printf("Removing a file from filelist\n");
//       }
//       if((strcmp(argv[3], "-u"))==0){
//         printf("Update contents of trove-file with filelist contents\n");
//       }
//     }
//     else{
//         printf("Invalid argument, please use -f && -b/-r/-u\n");
//     }

//checking if third arg is a word
  if(isalpha(atoi(argv[2])) != 0)
  {
    printf("File name should not contain digits!\n");
    exit(0);
  }
  
  makeFileList(&argv[1]);

  return 0;
}
