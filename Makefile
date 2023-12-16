####################################
# Makefile
####################################

all: bin/main

bin/main: bin/main.o bin/map.o
	gcc -o bin/main bin/main.o bin/map.o

bin/main.o: src/main.c include/map.h
	gcc -c -o bin/main.o src/main.c

bin/map.o: src/map.c include/map.h
	gcc -c -o bin/map.o src/map.c