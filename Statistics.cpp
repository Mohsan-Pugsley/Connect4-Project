#include "Statistics.h"
#include <string>

Statistics::Statistics() {
}

void Statistics::initialize() {
    filePath = "statFile.txt";
    std::ofstream outFile(filePath);
    std::ifstream inFile(filePath);
}

void Statistics::saveData() {
    if (!outFile) {
        std::cout << "Cannot open" << std::endl;
    }
    outFile << "Hello World File!!!!!" << std::endl;
}

void Statistics::loadData() {

}