#include "Computer.h"
#include "Board.h"
#include "Menu.h"
#include <random>
#include <time.h>
#include <iostream>

void Computer::setMenu(Menu m){
    this->m=m;
}

Computer::Computer() {
    colCount = 0; 
    rowCount = 0;
    lastMoveCol = floor(colCount/2);
    srand(time(NULL)); // Generates random seed for random using time
}

void Computer::setCols(int cols) {
    colCount = cols;
    lastMoveCol = floor(colCount/2);
}

void Computer::setRows(int rows) {
    rowCount = rows;
}

void Computer::move(bool * full){
    
    int randomCol = rand() % colCount + 1 ; // + 1 offsets from 0

    if (checkCondition() == true){
                    if (randomCol < lastMoveCol) {
                        if (rand() % 3 + 1 < 3) { // 2/3rds of the time
                            randomCol++; // move the randomCol closer to lastMoveCol
                        }
                    } else if (randomCol > lastMoveCol) {
                        if (rand() % 3 + 1 < 3) {
                            randomCol--; // move the randomCol closer to lastMoveCol
                        }
                    } // current result of this is that the computer chooses the edge columns less as well

    } else{
        while (checkCondition() == false){
            randomCol = rand() % colCount + 1 ;
            if (randomCol < lastMoveCol) {
                if (rand() % 3 + 1 < 3) { // 2/3rds of the time
                     randomCol++; // move the randomCol closer to lastMoveCol
                }
            } else if (randomCol > lastMoveCol) {
                if (rand() % 3 + 1 < 3) {
                    randomCol--; // move the randomCol closer to lastMoveCol
                }
            } // current result of this is that the computer chooses the edge columns less as well

    }   

    }
        lastMoveCol = randomCol;
        cout<<"Computer's move: " << lastMoveCol << endl;
    
}

bool Computer::checkCondition(){
    for(int i=0; i<rowCount; i++){
        if(playerCheck[i][lastMoveCol] == false){
            return true;
        }
    }
    return false;
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