#include <iostream>
#include <string>

struct MyStruct {
    std::string part1;
    std::string part2;
    std::string part3;
    std::string part4;
    std::string part5;
};

void parseString(const std::string& input, MyStruct& result) {
    if (input.length() != 20) {
        std::cerr << "Error: Input string must be exactly 20 characters long." << std::endl;
        return;
    }

    result.part1 = input.substr(0, 4);
    result.part2 = input.substr(4, 4);
    result.part3 = input.substr(8, 4);
    result.part4 = input.substr(12, 4);
    result.part5 = input.substr(16, 4);
}

int main() {
    std::string inputString = "12345678901234567890";

    MyStruct result;
    parseString(inputString, result);

    // Printing the result
    std::cout << "Part 1: " << result.part1 << std::endl;
    std::cout << "Part 2: " << result.part2 << std::endl;
    std::cout << "Part 3: " << result.part3 << std::endl;
    std::cout << "Part 4: " << result.part4 << std::endl;
    std::cout << "Part 5: " << result.part5 << std::endl;

    return 0;
}