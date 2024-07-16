#include <iostream>

enum Day {  
            sunday=0, 
            monday=1, 
            tuesday=2, 
            wednesday=3, 
            thursday=4, 
            friday=5, 
            saturday=6
        };

// by default it will go from 0 to n if you dont specify the number
enum Flavor {
    vanilla,
    chocolate,
    strawberry,
    mint
};

int main () {

    Day today = sunday;

    switch(today){
        case 0: std::cout << "Its sunday" << std::endl; break;
        case monday: std::cout << "Its monday" << std::endl; break;
        case 2: std::cout << "Its tuesday" << std::endl; break;
        case wednesday: std::cout << "Its wednesday" << std::endl; break;
        case 4: std::cout << "Its thursday" << std::endl; break;
        case friday: std::cout << "Its friday" << std::endl; break;
        case 6: std::cout << "Its saturday" << std::endl; break;
    }

    return 0;
}