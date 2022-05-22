#include "Menu.h"
#include "Board.h"
#include "Player.h"
#include "Person.h"
#include "Computer.h"
#include <iostream>
using namespace std;

int main(){
    Menu menu;
    Person person;
    Computer computer;

    menu.displayMenu(); 
    menu.setPlayerOption();
    int playerOption=menu.getPlayerOption();
    menu.setBoardRows();
    int nRows=menu.getBoardRows();
    menu.setBoardColumns();
    int nCols=menu.getBoardColumns();

    Player *Computer = &computer;
    Player *Person = &person;

    person.setMenu(menu);
    computer.setMenu(menu);
    computer.setCols(menu.getBoardColumns());
    computer.setRows(menu.getBoardRows());
    
    Board board(playerOption, nRows, nCols);

    board.printBoard();
    board.setBoardCheck();

    bool *columns = new bool[nCols];
        for(int i=0; i<nCols; i++){
            columns[i] = true;
    }
    
    // Check if player 1 can make their first move for person vs. person 
    if (playerOption == 1){
        // Person 1 input and print updated board
        person.setPlayerCheck(board.boardCheck);
        Person->move(columns, playerOption);
        board.updateBoard(person.getMove(), 'X');
        board.printBoard();

        // Person 2 input and print updated board
        person.setPlayerCheck(board.boardCheck);
        Person->move(columns, playerOption);
        board.updateBoard(person.getMove(), 'O');
        board.printBoard();

    // Check if player 1 can make their first move for person vs. computer 
    } else if (playerOption==2){
        // Person vs Computer
        // Person 1 input and print updated board
        person.setPlayerCheck(board.boardCheck);
        Person->move(columns, playerOption);
        board.updateBoard(person.getMove(), 'X');
        board.printBoard();

        // Person 2 input and print updated board
        computer.setPlayerCheck(board.boardCheck);
        Computer->move(columns, playerOption);
        board.updateBoard(computer.getMove(), 'O');
        board.printBoard();
    }
    return 0;
}