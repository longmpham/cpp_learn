#include <iostream>

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int* ptr = numbers; // Pointer pointing to the first element of the array
    int *ptrEnd = numbers + std::size(numbers) - 1;

    // Accessing array elements using the pointer
    for (int i = 0; i < 5; ++i) {
        // these lines both do the same thing!
        std::cout << "Element " << i << ": " << *ptr << std::endl;
        std::cout << "Element " << i << ": " << numbers[i] << std::endl;
        ++ptr; // Move the pointer to the next element
    }

    return 0;
}