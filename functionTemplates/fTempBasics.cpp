#include <iostream>
// template <typename T> // for one type
template <typename T, typename U> // for 2 types

// build max function for 2 inputs x and y

// the key here is to reduce redundancy!
// int max(int x, int y){
//     return (x > y) ? x : y;
// }

// double max(double x, double y){
//     return (x > y) ? x : y;
// }

// char max(char x, char y){
//     return (x > y) ? x : y;
// }

// for one data type input template
// T max(T x, T y){
//     return (x > y) ? x : y;
// }

// for two data type input template
auto max(T x, U y){
    return (x > y) ? x : y;
}

int main() {
    int x = 4;
    double y = 65;

    int themax = max(x,y);

    std::cout << "The max is: " << themax;
    

}