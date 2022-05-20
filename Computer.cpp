#include "Computer.h"
#include "Board.h"
#include "Menu.h"
#include <random>
#include <time.h>
#include <iostream>

Computer::Computer(){
    // Initialise variables
    colCount = 0; 
    rowCount = 0;
    lastMoveCol = floor(colCount/2);
    srand(time(nullptr));
}

void Computer::setMenu(Menu m){
    // Retrieve menu object
    this->m=m;
}

void Computer::setCols(int cols){
    // Sets the number of columns
    colCount = cols;
    lastMoveCol = floor(colCount/2);
}

void Computer::setRows(int rows){
    // Sets the number of rows
    rowCount = rows;
}
void Computer::setGeneratedMove() {
    int computerMove = rand() % colCount + 1; // + 1 offsets from 0

    if (computerMove < colCount && computerMove < lastMoveCol) {
        if (rand() % 5 + 1 < 5) { // 4/5ths of the time
            cout << "Hey1" << endl;
            computerMove++; // Move the randomCol closer to lastMoveCol
        }
    } else if (computerMove > 1 && computerMove > lastMoveCol) {
        if (rand() % 5 + 1 < 5) { // 4/5ths of the time
            cout << "Hey2" << endl;
            computerMove--; // Move the randomCol closer to lastMoveCol
        }
    }    // Current result of this is that the computer chooses the edge columns less as well
    
    // Sets the computerMove
    lastMoveCol = computerMove;
}

void Computer::move(bool * full){
    // Validates randomly generated integer
    setGeneratedMove();
    while (checkCondition(full) == false) {
        setGeneratedMove();
    }

    // Displays the computer's move
    cout<<"Computer's move: " << lastMoveCol << endl; 
}

bool Computer::checkCondition(bool * full){
    if (full[lastMoveCol-1] == false) {
        return false;
    }

    return true;
}

int Computer::getMove(){
    return lastMoveCol;
}


