#include <iostream>
#include <string>
#include <fstream>

class Statistics {
    private:

        std::string filePath;
        std::ofstream outFile; // creating
        std::ifstream inFile;

        int totalGames;
        int person1Wins;
        int person2Wins;
        int computerWins;

    public:
        Statistics();
        void initialize();
        int getData(std::string dataName);
        void updateData(std::string dataName, int value, bool override = false);
        bool editLine(std::string dataName, std::string &lineContents, int lineNum, int value, bool override);
        int getLineNumber(std::string dataName, int lineNum);
        std::string computeNewStringValue(int oldInt, int value, bool override);
};