# This makefile is used to build the program.
# Compil with -stdc11 -Wall -Werror
# We are linking trove.c trove.h


CC = gcc
CFLAGS = -std=c11 -Wall -Werror
LDFLAGS = -lm

all: trove

trove: trove.o
	$(CC) $(CFLAGS) -o trove trove.o $(LDFLAGS)

trove.o: trove.c trove.h

clean:
	rm -f *.o trove


