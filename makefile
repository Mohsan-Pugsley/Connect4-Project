CC = g++
CFlags = -Wall

main.o: main-board.cpp 
	$(CC) $(CFlags) Menu.cpp Player.cpp Person.cpp Computer.cpp Game.cpp Board.cpp main-board.cpp

