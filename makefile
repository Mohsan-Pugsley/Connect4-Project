CC = g++
CFlags = -Wall -lncurses

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp game.cpp menu.cpp board.cpp