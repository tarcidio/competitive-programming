CC = g++
CFLAGS = -Wall -g

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
program: main.o
	$(CC) $(CFLAGS) main.o -o program
	
all: program
run: program
	./program