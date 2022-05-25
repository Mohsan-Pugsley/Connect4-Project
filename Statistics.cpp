#include "Statistics.h"
#include <string>
#include <fstream>

#define filePath "statFile.txt" // The text file to store the statistics

Statistics::Statistics() {
}

int Statistics::getLineNumber(std::string dataName) { // Must be edited manually for new data entries
    if (dataName == "Person1Wins") {
        return 0; // Line 1
    } else if (dataName == "Person2Wins") {
        return 1;
    } else if (dataName == "ComputerWins") {
        return 2;
    } else if (dataName == "TotalGames") {
        return 3;
    }
    return -1; // Error code
}

std::string Statistics::computeNewStringValue(int oldInt, int value, bool override) {
    std::string newValue = std::to_string(value);
    // Adds the oldInt to the new value if not overrided
    if (override == false) {
        newValue = std::to_string((oldInt + value));
    }

    return newValue;
}

bool Statistics::editLine(std::string dataName, std::string &lineContents, int lineNum, int value, bool override) {
    int oldInt = std::stoi(lineContents);
    // Changes the referenced value of the line to the new string
    lineContents = computeNewStringValue(oldInt, value, override);

    return true;
}

void Statistics::updateData(std::string dataName, int value, bool override) {
    // Stream setup
    std::ifstream inStream(filePath); // Current file
    std::ofstream outStream("tempStats.txt"); // New file
    if (!inStream.is_open() || !outStream.is_open()) { // Error check
        std::cout << "Cannot open" << std::endl;
        exit(-1);
    }

    // Replacing old lines into new file
    std::string line;
    int lineNum = 0;
    while (getline(inStream, line)) {
        if (getLineNumber(dataName) == lineNum) { // If current line is the line to be edited
            editLine(dataName, line, lineNum, value, override); // edits line for it's contents
        }

        outStream << line << std::endl; // Replace line in file with line

        // Increment
        lineNum++;
    }

    // Temp names
    char temp_name[] = "tempStats.txt"; // Cannot use filePath for compiler
    char temp_old_name[] = filePath;

    std::rename(temp_name, temp_old_name); // Rename temp file to replace old file
    inStream.close();
    outStream.close();
}

int Statistics::getData(std::string dataName) {
    // Stream setup
    std::fstream fileStream(filePath); // I/O stream file
    if (!fileStream.is_open()) { // Error check
        std::cout << "Cannot open" << std::endl;
        exit(-1);
    }

    // Returning the desired line / data
    std::string line;
    int lineNum = 0;
    while (getline(fileStream, line)) {
        // If line has desired data.
        if (getLineNumber(dataName) == lineNum) {
            fileStream.seekg(std::ios::beg); // Sets the fstream to the start of the file
            fileStream.close();

            return std::stoi(line); // Returns current line
        }

        // Increment
        lineNum++;
    }
    return -3333; // Error code
}