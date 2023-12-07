#include <iostream>
using namespace std;

int main()
{
  cout <<"Hello World C++";
}

int variables()
{
    // Declare variables
    int num = 5;
    float floatNum = 3.14;
    char character = 'A';
    
    // Display values
    std::cout << "Integer: " << num << std::endl;
    std::cout << "Float: " << floatNum << std::endl;
    std::cout << "Character: " << character << std::endl;

    return 0;
}

int ifelse() {
    int x = 10;

    if (x > 5) {
        std::cout << "x is greater than 5" << std::endl;
    } else {
        std::cout << "x is not greater than 5" << std::endl;
    }

    return 0;
}


int loopdyloops() {
    // For loop
    for (int i = 0; i < 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // While loop
    int j = 0;
    while (j < 5) {
        std::cout << j << " ";
        ++j;
    }
    std::cout << std::endl;

    return 0;
}

int arraysandstrings() {
    // Arrays
    int numbers[5] = {1, 2, 3, 4, 5};

    // Strings
    std::string greeting = "Hello, C++!";

    // Accessing array elements
    std::cout << "Third number: " << numbers[2] << std::endl;

    // Accessing string elements
    std::cout << "First letter: " << greeting[0] << std::endl;

    return 0;
}