#include <iostream>

// Define a struct named Point
struct Point {
    // Data members
    double x;
    double y;

    // Member function to display the point
    void display() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    // Create an instance of the Point struct
    Point p1;

    // Access and modify the members
    p1.x = 2.5;
    p1.y = 3.7;

    // Call the member function
    p1.display();

    return 0;
}