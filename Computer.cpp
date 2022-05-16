#include "Computer.h"
#include "Board.h"
#include "Menu.h"
#include <random>
#include <time.h>
#include <iostream>
Computer::Computer() {
    colCount = 4; // does this need to be set to nCols?
    lastMoveCol = floor(colCount/2);
    srand(time(NULL)); // Generates random seed for random using time
}

void Computer::setCols(int cols) {
    colCount = cols;
}

void Computer::move(){
    cout<<"Computer's move: ";
    int randomCol = rand() % colCount + 1 ; // + 1 offsets from 0
     if (randomCol < lastMoveCol) {
         if (rand() % 3 + 1 < 3) { // 2/3rds of the time
             randomCol++; // move the randomCol closer to lastMoveCol
         }
     } else if (randomCol > lastMoveCol) {
         if (rand() % 3 + 1 < 3) {
             randomCol--; // move the randomCol closer to lastMoveCol
         }
     } // current result of this is that the computer chooses the edge columns less as well

    lastMoveCol = randomCol;
    cout<<lastMoveCol<<endl;
}

int Computer::getMove(){
    return lastMoveCol;
}

Computer::~Computer(){
}

/*
void Computer::move() {
    computeTurn();
}
void Computer::computeTurn() {
    int randomCol = rand() % colCount + 1 ; // + 1 offsets from 0
     if (randomCol < lastMoveCol) {
         if (rand() % 3 + 1 < 3) { // 2/3rds of the time
             randomCol++; // move the randomCol closer to lastMoveCol
         }
     } else if (randomCol > lastMoveCol) {
         if (rand() % 3 + 1 < 3) {
             randomCol--; // move the randomCol closer to lastMoveCol
         }
     } // current result of this is that the computer chooses the edge columns less as well

    lastMoveCol = randomCol;
}

int Computer::getTurn() {
    return lastMoveCol;
}
Computer::~Computer() {

}
*/