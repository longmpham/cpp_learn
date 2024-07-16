#include <iostream>

void mySwap(std::string x, std::string y);
void myBetterSwap(std::string &x, std::string &y);

int main() {

    std::string x = "HELLO";
    std::string y = "WORLD";

    // mySwap(x,y);
    myBetterSwap(x,y);
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}

void myBetterSwap(std::string &x, std::string &y){

    // pass by reference!

    std::string temp;
    temp = x;
    x = y;
    y = temp;
}


void mySwap(std::string x, std::string y){ // pass by value!
    std::string temp;

    temp = x;
    x = y;
    y = temp;
}