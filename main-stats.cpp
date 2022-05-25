#include "Statistics.h"

// Unit test
int main() {
    Statistics stats;

    std::cout << "Games won: " <<stats.getData("TotalGames") << std::endl; // Initial

    stats.updateData("Person1Wins", 4); // Line 1
    stats.updateData("Person1Wins", 1, true); // Overrides line 1 to "1"
    stats.updateData("Person2Wins", 7); // Line 2
    stats.updateData("ComputerWins", 13); // Line 3
    stats.updateData("TotalGames", 2); // Line 4, adds 2
    stats.updateData("Person1Wins", 9); // Line 1, sets to 10

    std::cout <<  "Games won: " << stats.getData("TotalGames") << std::endl; // Initial + 2
    std::cout << "Person 1 has won: " <<stats.getData("Person1Wins") << " times!" << std::endl; // 10

    return 0;
}