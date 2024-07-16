#include <iostream>

int searchArray(int array[], int size, int search);

// this is a linear search!
int main(){

    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int myNum;

    std::cout << "Enter a number to search for: ";
    std::cin >> myNum;

    index = searchArray(numbers, size, myNum);
    if (index == -1){
        std::cout << "No values were found!";
    }
    else{
        std::cout << "Found number at index: " << index;
    }

    return 0;
}

int searchArray(int array[], int size, int search){

    for (int i = 0; i < size; i++){
        if(array[i] == search){
            return i;
        }
    }
    return -1;
}