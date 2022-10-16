# This makefile is used to build the program.
# Compil with -stdc11 -Wall -Werror
# We are linking trove.c trove.h

CC = gcc
CFLAGS = -std=c11 -Wall -Werror
LDFLAGS = -lm

all: trove

project : trove.o
	gcc -std=c11 -Wall -Werror -o project trove.o

trove.o : trove.c trove.h
	gcc -std=c11 -Wall -Werror -c trove.c

directoryTraverser.o : 
	gcc -std=c11 -Wall -Werror -c directoryTraverser.c

clean :
	rm project trove.o
