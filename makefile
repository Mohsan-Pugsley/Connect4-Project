#MAKEFILE for Connect4 Project

CC = g++
CFlags = -Wall
HEADERS = Menu.h Player.h Person.h Computer.h Game.h Board.h 
FILES = Menu.o Player.o Person.o Computer.o Game.o Board.o main.o

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(FILES)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f core *.o 