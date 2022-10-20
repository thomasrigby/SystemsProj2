# This makefile is used to build the program.
# Compil with -stdc11 -Wall -Werror
# We are linking trove.c trove.h

CC = gcc
CFLAGS = -std=c11 -Wall -Werror
LDFLAGS = -lm
OBJECTS = trove.o directoryTraverser.o ds.o hash.o troveCheck.o 

all: trove

trove: $(OBJECTS)
	$(CC) $(CFLAGS) -o trove $(OBJECTS) $(LDFLAGS)

trove.o: trove.c trove.h

directoryTraverser.o: directoryTraverser.c trove.h

ds.o: ds.c trove.h

hash.o: hash.c trove.h

troveCheck.o: troveCheck.c trove.h



clean:
	rm -f trove $(OBJECTS)
