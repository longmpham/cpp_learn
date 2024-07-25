#include <iostream>
#include <string>


int main() {

    // get input from user
    // assumption: no whitespaces allowed and must be odd numbers
    std::cout << "Enter your letters to begin building the pyramid\n";
    std::string input {};
    std::cin >> input;

    /*
        pyramid grows by number of characters in the input
        therefore we need a size to determine that. Size grows by 1,3,5,... odd numbers basically. 
        Each row is essentially a palindrome starting from the first letter to the nth letter
        whatever characters that are unused (n-current) are whitespaces
        input = ABC
        size = 3
          wwAww
          wABAw
          ABCBA
   
        input = ABCDE
        size = 5
        wwwwAwwww
        wwwABAwww
        wwABCBAww
        wABCDCBAw
        ABCDEDCBA
    */

    int size = input.length();
    std::string w {"*"};
    for (int i {0}; i < size; i++){
        int numWS = size - (i+1);
        // white space
        for(int j {0}; j < numWS; j++){
            std::cout << w;
        }

        // letters
        for (int k {0}; k < i+1; k++){
            std::cout << input[k];
        }
        for (int k {i}; k > 0; k--){
            std::cout << input[k-1];
        }

        // white space
        for(int j {0}; j < numWS; j++){
            std::cout << w;
        }
        std::cout << std::endl;
    }



    return 0;
}