//Project 2 which creates a command line utility program 
//to build, find and compress files 

#include "trove.h"


//report the program's synopsis, should a command-line process detect errors
// int usage()
// {
// }

//Searching through directory to find file
int findFile(char *fileName)
{  
  return 0;
}

//Building a file 
int buildFile()
{
  return 0;
}

//Modifying the file 
int modifyFile()
{
  return 0;
}
//main function to receive and validate the command-line options and arguments
//command line format is  ./trove  [-f trovefile]  word 
// command line format is ./trove  [-f trovefile]  [-b  |  -r  |  -u]  [-l length]  filelist
int main(int argc, char *argv[])
{
  directoryTraverser(argv[1]);

  if(argc < 3) //3 arguments required to find file 
  {
    printf("Not enough arguments to find file\n");
    exit(0);
  } 
  else if (argc == 3 && strcmp(argv[1], "-f") == 0) // ensures second argument is to find file
  {
    if(strlen(argv[2]) < 3) //minimum length of the word is 3 characters
    {
        printf("Word has to be minimum of 3 characters\n");
        exit(0);
      }
    else{
    printf("Finding file to create %s file\n", argv[2]);
  }
}
  else if (argc != 7)
  {
    printf("Not enough arguments\n");
  }
  else if((strcmp(argv[1],"-f") == 0))
    {
      if((strcmp(argv[3], "-b"))==0){
        printf("Build a file named %s \n", argv[2]);
      }
      if((strcmp(argv[3], "-r"))==0){
        printf("Removing a file from filelist\n");
      }
      if((strcmp(argv[3], "-u"))==0){
        printf("Update contents of trove-file with filelist contents\n");
      }
    }
    else{
        printf("Invalid argument, please use -f && -b/-r/-u\n");
    }

//checking if third arg is a word
  if(isalpha(atoi(argv[2])) != 0)
  {
    printf("File name should not contain digits!\n");
    exit(0);
  }
}
