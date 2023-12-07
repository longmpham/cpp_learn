#include <iostream>

// Define a class named Circle
class Circle {
private:
    // Data members
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Member function to calculate the area
    double calculateArea() {
        return 3.14 * radius * radius;
    }

    // Getter function to retrieve the radius
    double getRadius() const {
        return radius;
    }

    // Setter function to set the radius
    void setRadius(double r) {
        radius = r;
    }
};

int main() {
    // Create an instance of the Circle class
    Circle myCircle(5.0);

    // Access and modify the members
    double area = myCircle.calculateArea();
    std::cout << "Area: " << area << std::endl;

    // Use getter and setter
    std::cout << "Radius before: " << myCircle.getRadius() << std::endl;
    myCircle.setRadius(7.0);
    std::cout << "Radius after: " << myCircle.getRadius() << std::endl;

    return 0;
}
