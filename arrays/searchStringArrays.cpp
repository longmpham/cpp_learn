#include <iostream>
int searchArray(std::string array[], int size, std::string element);

int main(){

    std::string foods[] = {"pizza", "hamburger", "hotdog"};

    std::string search = "hotdog";
    int size = sizeof(foods) / sizeof(foods[0]);

    int result = searchArray(foods, size, search);

    if (result >= 0){
        std::cout << "Your search term: " << search << " was found at index: " << result << std::endl;
    }
    else{
        std::cout << "Your search term: " << search << " was not found";
    }

    return 0;
}

int searchArray(std::string array[], int size, std::string element){

    for (int i = 0; i < size; i++){
        if (array[i] == element) return i;
    }
    return -1;

}