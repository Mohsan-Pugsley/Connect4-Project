#include "Statistics.h"

int main() {
    Statistics stats;

    std::cout << "Games won: " <<stats.getData("TotalGames") << std::endl;

    stats.updateData("Person1Wins", 4);
    stats.updateData("Person1Wins", 1, true);
    stats.updateData("Person2Wins", 7);
    stats.updateData("ComputerWins", 13);
    stats.updateData("TotalGames", 2);
    stats.updateData("Person1Wins", 9);

    std::cout <<  "Games won: " << stats.getData("TotalGames") << std::endl;
    std::cout << "Person 1 has won: " <<stats.getData("Person1Wins") << " times!" << std::endl;

    return 0;
}