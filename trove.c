//Project 2 which creates a command line utility program 
//to build, find and compress files 

#include "trove.h"

//main function to receive and validate the command-line options and arguments
//command line format is  ./trove  [-f trovefile]  word 
// command line format is ./trove  [-f trovefile]  [-b  |  -r  |  -u]  [-l length]  filelist
int main(int argc, char *argv[]){
  char *word = argv[3];
  char *trovefile = "/tmp/trove";
  char *source = argv[2];
  int opt;
  int argFlag = 0;
  int length = 4;
  char *homeDir = ".";
  char fileList[1024]="";

  //Concatenation 
  // char startArr[strlen(source)+1];
  // strcpy(startArr, source);
  // char final [strlen(startArr)+1];
  // strcpy(final, startArr);
  // strcat(homeDir, final);

//Call to find trove file and search for word 
traverseDirectory(homeDir, source, word);
  //We are using opt to get the command line options
  while ((opt = getopt(argc, argv, "f:brul:")) != -1) {
    switch (opt) {
    case 'f':
      trovefile = optarg;
      break;
    case 'b':
      if (argFlag == 0) {
        argFlag = 1;
        break;
      } else {
        printf("Error: Too many arguments\n");
        exit(1);
      }
    case 'r':
      if (argFlag == 0) {
        argFlag = 2;
        break;
      } else {
        printf("Error: Too many arguments\n");
        exit(1);
      }
    case 'u':
      if (argFlag == 0) {
        argFlag = 3;
        break;
      } else {
        printf("Error: Too many arguments\n");
        exit(1);
      }
    case 'l':
      length = atoi(optarg);
      break;
    default:
      fprintf(stderr, "Usage: %s [-f trovefile] [-b | -r | -u] [-l length] filelist\n", argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if(argFlag == 0){
    char *word = argv[optind];
    printf("word: %s\n", word);
    //findWordInList(trovefile, &word);
  }
  else if(argFlag == 1){    
      for(optind = optind; optind < argc; optind++){
        printf("adding %s to the filelist\n", argv[optind]);
        strcat(fileList, "|");
        strcat(fileList, argv[optind]);
      }
      printf("The full filelist is %s \n", fileList);
      printf("Building trove file %s from filelist %s with length %d\n", trovefile, fileList, length);
  }
  else if(argFlag == 2){
    for(optind = optind; optind < argc; optind++){
      printf("adding %s to the filelist\n", argv[optind]);
      strcat(fileList, "|");
      strcat(fileList, argv[optind]);
    }
    printf("The full filelist is %s \n", fileList);
    printf("Removing filelist %s from trove file %s\n", fileList, trovefile);
    
  }
  else if(argFlag == 3){
    for(optind = optind; optind < argc; optind++){
      printf("adding %s to the filelist\n", argv[optind]);
      strcat(fileList, "|");
      strcat(fileList, argv[optind]);
    }
    printf("The full filelist is %s \n", fileList);
    printf("Updating trove file %s with filelist %s\n", trovefile, fileList);
  }
  else{
    printf("Error: Invalid argument\n");
    exit(1);
  }
    // troveCheck(&argv[2]);
    // printHashTable(); //printing hash table before checks for now
    // printf("Filelist has been made from %s\n", argv[2]);
  return 0;
}
