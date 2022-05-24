#include "Statistics.h"

int main() {
    Statistics stats;
    stats.initialize();

    //std::cout << "Games won: " <<stats.getData("TotalGames") << std::endl;

    stats.updateData("Person1Wins", 3);
    stats.updateData("Person1Wins", 5, true);
    stats.updateData("Person2Wins", 7);
    stats.updateData("ComputerWins", 13);
    stats.updateData("TotalGames", 2);

    //std::cout <<  "Games won: " << stats.getData("TotalGames") << std::endl;
    //std::cout << "Person 1 has won: " <<stats.getData("Person1Wins") << " times!" << std::endl;

    return 0;
}