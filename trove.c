//Project 2 which creates a command line utility program 
//to build, find and compress files 

#include "trove.h"

//main function to receive and validate the command-line options and arguments
//command line format is  ./trove  [-f trovefile]  word 
// command line format is ./trove  [-f trovefile]  [-b  |  -r  |  -u]  [-l length]  filelist
int main(int argc, char *argv[]){
  char *word = argv[3];
  char *trovefile = "/tmp/trove";
  int opt;
  int argFlag = 0;
  int length = 4;
  char *homeDir = ".";
    
    traverseDirectory(homeDir, word); //calling before checks (temporary)
    //printf("%s", PATH);
   //troveCheck(&argv[2]);
 
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
    if (argc - optind != 1) {
      fprintf(stderr, "Usage: %s [-f trovefile] word\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    else{
      char *word = argv[optind];
      printf("word: %s\n", word);
      //findWordInList(trovefile, &word);
    }
  }
  else if(argFlag == 1){    
    if (argc - optind != 1) {
      fprintf(stderr, "Usage: %s [-f trovefile] [-b] [-l length] filelist\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    else{
      char *filelist = argv[optind];
      // buildTrove(trovefile, filelist, length);
      printf("Building trove file %s from filelist %s with length %d\n", trovefile, filelist, length);
    }
  }
  else if(argFlag == 2){
    if (argc - optind != 1) {
      fprintf(stderr, "Usage: %s [-f trovefile] [-r] [-l length] filelist\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    else{
      char *filelist = argv[optind];
      printf("Removing from trove file %s from filelist %s with length %d\n", trovefile, filelist, length);
      // removeFile(trovefile, filelist, length);
    }
  }
  else if(argFlag == 3){
    if (argc - optind != 1) {
      fprintf(stderr, "Usage: %s [-f trovefile] [-u] filelist\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    else{
      char *filelist = argv[optind];
      printf("Updating trove file %s from filelist %s\n", trovefile, filelist);
      // updateTrove(trovefile, filelist);
    }
  }
  else{
    printf("Error: Invalid argument\n");
    exit(1);
  }
    //troveCheck(&argv[2]);
    //traverseDirectory(argv[2]); //calling before checks (temporary)
    //printHashTable(); //printing hash table before checks for now
    //printf("Filelist has been made from %s\n", argv[2]);
  return 0;
}
