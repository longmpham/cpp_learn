#include <iostream>

int main(){

    std::string car = "someCar";
    std::string undeclaredCars[3]; // make sure to set the size in the [ size ] 
    std::string cars[] = {"car1", "car2", "car3"};

    cars[0] = "notacar";

    std::cout << cars[0] << std::endl;
    std::cout << cars[1] << std::endl;
    std::cout << cars[2] << std::endl;



    return 0;
}