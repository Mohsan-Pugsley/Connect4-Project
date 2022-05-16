#include <iostream>
#include <string>
#include <fstream>

class Statistics {
    private:

        std::string filePath;
        std::ofstream outFile; // creating
        std::ifstream inFile;

        int leastMovesRecord;
        int computerLoses;

    public:
        Statistics();
        void initialize();
        void saveData();
        void loadData();
};