CC = g++
CFlags = -Wall
DEPS = Menu.h Player.h Person.h Computer.h Game.h Board.h 
OBJ = Menu.o Player.o Person.o Computer.o Game.o Board.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f core *.o 
	