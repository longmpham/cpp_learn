#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Function to find a string in a file
bool findStringInFile(const std::string& filePath, const std::string& searchString) {
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file for reading." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.find(searchString) != std::string::npos) {
            std::cout << "Found: " << searchString << " in line: " << line << std::endl;
            inputFile.close();
            return true;
        }
    }

    std::cout << "String not found in the file." << std::endl;
    inputFile.close();
    return false;
}

// Function to append a string to a file
void appendStringToFile(const std::string& filePath, const std::string& newString) {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for appending." << std::endl;
        return;
    }

    outputFile << newString << std::endl;

    std::cout << "Appended: " << newString << " to the file." << std::endl;
    outputFile.close();
}

int main() {
    // Example of reading from a file
    std::string filePath = "randomHexValues.txt";

    // Example of finding a string in the file
    findStringInFile(filePath, "D0B");

    // Example of appending a string to the file
    appendStringToFile(filePath, "1029573AB9");

    return 0;
}
