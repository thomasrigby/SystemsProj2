//Project 2 which creates a command line utility program 
//to build, find and compress files 

#include "trove.h"

//main function to receive and validate the command-line options and arguments
//command line format is  ./trove  [-f trovefile]  word 
// command line format is ./trove  [-f trovefile]  [-b  |  -r  |  -u]  [-l length]  filelist
int main(int argc, char *argv[]){
  char *trovefile = "/tmp/trove.txt";
  int opt;
  int argFlag = 0;
  int length = 4;
  LIST *fl = malloc(sizeof(LIST));
 
  //CALLING REALPATH to find realpath of trove-file

  //Call to find trove file and search for word 
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
     //See if trove file exists from optind - 1(if not specified, /tmp/trove is standard)
     //if it does...print pathnames with desired word from hash
     //if it doesn't throw error
     int word = hashValue(argv[optind]);
     if(strcmp(argv[1], "-f")==0)
     {
        char str [strlen(argv[2])+1];
        strcpy(str, ".");
        strcat(str, argv[2]);
        findTrove(str, word);
     }
     else{
        char str [strlen(trovefile)+1];
        strcpy(str, ".");
        strcat(str, trovefile);
        findTrove(str, word);
     }
    }
  }
  else if(argFlag == 1){    
    if (argc - optind == 0) {
      fprintf(stderr, "Usage: %s [-f trovefile] [-b] [-l length] filelist\n", argv[0]);
      exit(EXIT_FAILURE);
    } else {
      for(int i = optind; i < argc; i++){
          char *filelist = argv[i];
          fl = addToList(fl, filelist);
      }
      char str [strlen(trovefile)+1];
      strcpy(str, ".");
      strcat(str, trovefile);
      buildTrove(fl, str, length);
    }
  }
  else if(argFlag == 2){
     for(int i = optind; i < argc; i++){
          char *filelist = argv[i];
          fl = addToList(fl, filelist);
      }
      char str [strlen(trovefile)+1];
      strcpy(str, ".");
      strcat(str, trovefile);
      printf("%s\n", str);
      removeFileFromTrove(fl, str);
  }
  else if(argFlag == 3){
    for(int i = optind; i < argc; i++){
      char *filelist = argv[i];
      fl = addToList(fl, filelist);
    }
    char str [strlen(trovefile)+1];
    strcpy(str, ".");
    strcat(str, trovefile);
    updateTroveFile(fl, str, length);
  }
  else{
    printf("Error: Invalid argument\n");
    exit(1);
  }
  return 0;
}
