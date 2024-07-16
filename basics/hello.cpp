// setup guide, follow this video to compile using VSCode, MinGW, and VSCode ext. to run C++
// https://www.youtube.com/watch?v=pJ7iOcxfpEQ
// to run the program, in terminal, "g++ hello.cpp", which will output a a.out file. finally, "./a" will execute the program


#include <iostream>
// using namespace std;
int main()
{
  std::string name;
  std::cout << "Hello World C++" << std::endl;
  std::cout << "What is your name? ";
  std::cin >> name; // getline(std::cin, name) is used for the entire line input (white spaces!)
  // std::getline(std::cin >> std::ws, name)
  std::cout << "Your name is " << name << std::endl;
}