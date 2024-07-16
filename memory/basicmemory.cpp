#include <iostream>

int main(){

    std::string name = "Me!";
    int age = 25;
    bool student = true;

    std::cout << &name << std::endl; // prints address owned by name
    std::cout << &age << std::endl; // " by age"
    std::cout << &student << std::endl; // etc.

    return 0;
}