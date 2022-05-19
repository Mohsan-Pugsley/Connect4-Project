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

void Computer::move(bool * full){
    // Validates randomly generated integer
    while (checkCondition(full) == false) {
        int computerMove = rand() % colCount + 1; // + 1 offsets from 0
        if (computerMove < colCount || computerMove < lastMoveCol) {
            if (rand() % 3 + 1 < 3) { // 2/3rds of the time
                computerMove++; // Move the randomCol closer to lastMoveCol
            }
        } else if (computerMove > colCount || computerMove > lastMoveCol) {
            if (rand() % 3 + 1 < 3) { // 2/3rds of the time
                    computerMove--; // Move the randomCol closer to lastMoveCol
            }
        }    // Current result of this is that the computer chooses the edge columns less as well
        lastMoveCol = computerMove;
    }
    
    // Displays the computer's move
    cout<<"Computer's move: " << lastMoveCol << endl; 
}

bool Computer::checkCondition(bool * full){
    // Validates input
    // for(int i=0; i<rowCount; i++){
    //     if(playerCheck[i][lastMoveCol] == false){
    //         return false;
    //     }
    // }

    if (full[lastMoveCol-1] == false) {
        return false;
    }

    return true;
}

int Computer::getMove(){
    return lastMoveCol;
}


