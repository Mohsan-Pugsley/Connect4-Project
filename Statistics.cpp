#include "Statistics.h"
#include <string>
#include <cstring>
#include <fstream>
#include <limits>

Statistics::Statistics() {
}

void Statistics::initialize() {
    filePath = "statFile.txt";
}

int Statistics::getLineNumber(std::string dataName, int lineNum) {
    if (dataName == "Person1Wins") {
        return 1; // Line number
    } else if (dataName == "Person2Wins") {
        return 2;
    } else if (dataName == "ComputerWins") {
        return 3;
    } else if (dataName == "TotalGames") {
        return 4;
    }
    return 0;
}

std::string Statistics::computeNewStringValue(int oldInt, int value, bool override) {
    std::string newValue = std::to_string(value);
    if (override == false) {
        newValue = std::to_string(oldInt + value);
    }
    return newValue;
}

bool Statistics::editLine(std::string dataName, std::string &lineContents, int lineNum, int value, bool override) {
    int oldInt = std::stoi(lineContents);
    int lineToEdit = getLineNumber(dataName, lineNum);
    if (lineToEdit == 1) {
        lineContents = computeNewStringValue(oldInt, value, override);
        return true;
    } else if (lineToEdit == 2) {
        lineContents = computeNewStringValue(oldInt, value, override);
        return true;
    } else if (lineToEdit == 3) {
        lineContents = computeNewStringValue(oldInt, value, override);
        return true;
    } else if (lineToEdit == 4) {
        lineContents = computeNewStringValue(oldInt, value, override);
        return true;
    }

    return false;
}

void Statistics::updateData(std::string dataName, int value, bool override) {
    std::fstream fileStream(filePath);

    if (!fileStream.is_open()) { // Error check
        std::cout << "Cannot open" << std::endl;
        exit(-1);
    }

    std::string line;
    int lineNum = 0;
    while (getline(fileStream, line)) {
        // Increment
        lineNum++;

        editLine(dataName, line, lineNum, value, override); // edits line for it's contents
        if (getLineNumber(dataName, lineNum) == lineNum) {
            fileStream.seekg(std::ios::beg); // Sets the fstream to the start of the file
            // Iterates and ignores every line but lineNum in fstream
            for(int i=0; i < lineNum - 1; ++i) {
                fileStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            std::cout << "New data for " << dataName << " is: " << line << std::endl;
            fileStream << line; //std::flush(); // New value to fstream
            fileStream.close();
        }
    }
}


int Statistics::getData(std::string dataName) {
    std::fstream fileStream(filePath);
    if (!fileStream.is_open()) { // Error check
        std::cout << "Cannot open" << std::endl;
        exit(-1);
    }

    std::string line;
    int lineNum = 1;
    while (getline(fileStream, line)) {
        // If line has desired data.
        if (lineNum == getLineNumber(dataName, lineNum)) {
            fileStream.seekg(std::ios::beg); // Sets the fstream to the start of the file
            // Iterates and ignores every line but lineNum in fstream
            for(int i=0; i < lineNum - 1; ++i) {
                fileStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            fileStream.close();
            return std::stoi(line);
        }

        // Increment
        lineNum++;
    }
    return -3333; // Error code
}