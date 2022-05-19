CC = g++
CFlags = -Wall

main.o: main.cpp
	$(CC) $(CFlags) Menu.cpp Player.cpp Person.cpp Computer.cpp Game.cpp Board.cpp main.cpp
