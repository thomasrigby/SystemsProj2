//header file to define structs to store directories and values 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//creating a construct that stores the valyes of the files in the filelist 
//for the trove file to traverse through and determine x/y/z
struct filelist
{
    char name; 
    int nameLength; 
    char pathname;
    char directory;
};