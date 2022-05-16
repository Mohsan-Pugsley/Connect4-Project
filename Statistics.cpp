#include "Statistics.h"
#include <string>
#include <fstream>

Statistics::Statistics() {
}

void Statistics::initialize() {
    filePath = "statFile.txt";
    std::ofstream outFile(filePath); // may not need to be set here
    std::ifstream inFile(filePath);
}

void Statistics::saveData() {
    std::ofstream outFile(filePath); // needs to be set here
    std::cout << "Writing..." << std::endl;
    if (!outFile) {
        std::cout << "Cannot open" << std::endl;
        exit(-1); // no idea what this does
    }
    outFile << "Hello World File!!!!!" << "\nNext Line" << std::endl;
}

void Statistics::loadData() {

}