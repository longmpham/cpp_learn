#include <iostream>

void walk(int steps);

int main(){

    walk(5);
    return 0;
}

void walk(int steps){

    if (steps > 0){
        std::cout << "You are at step: " << steps << std::endl;
    walk(steps - 1);
    }
    else{
        std::cout << "You have finished walking." << std::endl;
    }
}