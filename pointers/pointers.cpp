#include <iostream>
using namespace std;

int main()
{
  int number = 42;
  int *pNumber;

  pNumber = &number;

  cout << pNumber << endl; // address of pointer
  cout << &pNumber << endl; // address of the thing the pointer is pointing to
  cout << *pNumber << endl; // dereference the thing the pointer is pointing to

  return 0;
}

// 1. Declaring Pointers:
// You declare a pointer using the asterisk (*) symbol. For example:

int declaringPointers() {
    int number = 42;
    int *pointerToNumber;  // Declaration of a pointer

    pointerToNumber = &number;  // Assigning the address of 'number' to the pointer

    return 0;
}

// 2. Accessing Values through Pointers:
// You can access the value a pointer is pointing to using the dereference operator *:

int accessingPointers() {
    int number = 42;
    int *pointerToNumber = &number;

    // Accessing the value through the pointer
    cout << "Value of 'number': " << *pointerToNumber << endl;

    return 0;
}

// 3. Pointer Arithmetic:
// You can perform arithmetic operations on pointers. When you add an integer to a pointer, 
// it moves to the memory location corresponding to that offset:

int pointerArithmetic() {
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;  // Points to the beginning of the array

    // Accessing array elements through pointer and pointer arithmetic
    cout << "Element at index 2: " << *(ptr + 2) << endl;

    return 0;
}

// 4. Dynamic Memory Allocation:
// You can allocate memory dynamically using new and deallocate it using delete:

int dynmaicMemoryAllocation() {
    int *dynamicNumber = new int;  // Dynamically allocated integer

    *dynamicNumber = 100;  // Assigning a value to the dynamically allocated memory

    cout << "Value stored in dynamicNumber: " << *dynamicNumber << endl;

    delete dynamicNumber;  // Deallocating the dynamically allocated memory

    return 0;
}

// 5. Pointers and Functions:
// Passing pointers to functions allows you to modify the original data outside the function:

void modifyValue(int *ptr) {
    *ptr = 99;
}

int pointersAndFunctions() {
    int originalValue = 42;
    int *pointerToValue = &originalValue;

    modifyValue(pointerToValue);

    cout << "Modified value: " << originalValue << endl;

    return 0;
}

// Remember to handle pointers carefully to avoid memory leaks and undefined behavior. 
// The use of smart pointers (like std::unique_ptr and std::shared_ptr) is encouraged 
// to manage memory more safely.