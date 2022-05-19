CC = g++
CFlags = -Wall

main: main.o Menu.o Board.o Game.o Player.o Person.o Computer.o
	$(CC) $(CFlags) -o main main.o Menu.o Board.o Game.o Player.o Person.o Computer.o

main.o: main.cpp Menu.h Board.h Game.h Player.h Person.h Computer.h
	$(CC) $(CFlags) -c main.cpp

Menu.o: Menu.h

Board.o: Board.h

Game.o: Game.h

Player.o: Player.h

Person.o: Person.h

Computer.o: Computer.h