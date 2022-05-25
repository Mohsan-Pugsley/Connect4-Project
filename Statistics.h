#include <iostream>
#include <string>

// This class handles 4 statistical, integer values
// These are: "Person1Wins", "Person2Wins", "ComputerWins", "TotalGames"
// getData & updateData methods manipulate the stored data.

class Statistics {
    private:
        // editLine: edits a line to contain a new value from integers - see .cpp
        bool editLine(std::string dataName, std::string &lineContents, int lineNum, int value, bool override = false);
        int getLineNumber(std::string dataName); // Returns the line number containing given data name
        std::string computeNewStringValue(int oldInt, int value, bool override); // Computes new string from ints
    public:
        Statistics(); // Constructor
        int getData(std::string dataName); // Given a dataName, returns the int value
        // updateData: Updates a dataName, given int and optional parameter to override old value
        void updateData(std::string dataName, int value, bool override = false);
};