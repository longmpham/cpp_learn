#include <iostream>

int main(){

    char *pGrades = NULL; // use NULL to init pointers as good practice
    int size;

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;

    pGrades = new char[size];

    for(int i = 0; i < size; i++){
        char grade;
        std::cout << "Enter grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }

    for(int i = 0; i < size; i++){
        std::cout << pGrades[i] << " ";
    }

    delete[] pGrades; // if using Heap, delete (use new -> use delete!)

    return 0;
}