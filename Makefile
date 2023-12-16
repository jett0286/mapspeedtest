####################################
# Makefile
####################################

all: bin/main

bin/main: src/main.c
	gcc -o bin/main src/main.c