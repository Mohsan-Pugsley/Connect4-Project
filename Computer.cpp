#include "Computer.h"
#include <random>
#include <time.h>

Computer::Computer() {
    colCount = 5;
    srand(time(NULL)); // Generates random seed for random using time
}

void Computer::move() {
    computeTurn();
}
void Computer::computeTurn() {
    int randomCol = rand() % colCount + 1; // + 1 offsets from 0
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