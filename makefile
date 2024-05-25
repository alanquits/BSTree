CC = gcc
FLAGS = -Wall
OBJECTS = example.o bstree.o

example: $(OBJECTS)
	$(CC) $(OBJECTS) -o example

example.o: example.c
	$(CC) -c example.c $(FLAGS)

bstree.o: bstree.c bstree.h
	$(CC) -c bstree.c $(FLAGS)
