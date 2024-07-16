#include <iostream>


struct Car {
    std::string model;
    int year;
    std::string color;
};

void printCar(Car &car);
void paintCar(Car &car, std::string color);

int main() {

    Car car1;
    Car car2;

    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "Black";
    
    car2.model = "Corvette";
    car2.year = 2022;
    car2.color = "Red";

    printCar(car1);
    printCar(car2);

    paintCar(car1, "green");

    printCar(car1);
    printCar(car2);

    return 0;
}

void printCar(Car &car) {
    std::cout << car.model << std::endl;
    std::cout << car.year << std::endl;
    std::cout << car.color << std::endl;
}

void paintCar(Car &car, std::string color){
    car.color = color;
}