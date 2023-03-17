#Variables
CC = g++
CFLAGS = -Wall -g
#Construction of the "main.o"
main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
#Construction of the "program"
program: main.o
	$(CC) $(CFLAGS) main.o -o program
all: program
#Command "run"
run: program
	./program