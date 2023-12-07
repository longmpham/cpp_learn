#include <iostream>

int main() {
    int x = 5;
    int *ptr = &x;

    std::cout << *ptr << std::endl;

    return 0;
}

// What is the output of this program?
// a) 5
// b) &x
// c) 0
// d) Error


#include <iostream>

int main() {
    int y = 10;
    int *p = &y;
    *p = 20;

    std::cout << y << std::endl;

    return 0;
}

// What is the output of this program?
// a) 10
// b) 20
// c) &y
// d) Error


#include <iostream>

int main() {
    int a = 5;
    int *ptr1 = &a;
    int *ptr2 = ptr1;

    *ptr2 = 8;

    std::cout << a << std::endl;

    return 0;
}

// What is the output of this program?
// a) 5
// b) 8
// c) &a
// d) Error


#include <iostream>

int main() {
    int a = 5;
    int *ptr1 = &a;
    int *ptr2 = ptr1;

    *ptr2 = 8;

    std::cout << a << std::endl;

    return 0;
}

// What is the output of this program?
// a) 5
// b) 8
// c) &a
// d) Error


#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    int *ptr = &x;
    ptr = &y;

    std::cout << *ptr << std::endl;

    return 0;
}

// What is the output of this program?
// a) 10
// b) 20
// c) &y
// d) Error


#include <iostream>

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = numbers;

    std::cout << *ptr << std::endl;

    return 0;
}

// What is the output of this program?
// a) 1
// b) 2
// c) &numbers[0]
// d) Error


#include <iostream>

void modifyValue(int *ptr) {
    *ptr = 50;
}

int main() {
    int value = 10;
    modifyValue(&value);

    std::cout << value << std::endl;

    return 0;
}

// What is the output of this program?
// a) 10
// b) 50
// c) &value
// d) Error

#include <iostream>

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {
        std::cout << "The pointer is null." << std::endl;
    } else {
        std::cout << "The pointer is not null." << std::endl;
    }

    return 0;
}

// What is the output of this program?
// a) The pointer is null.
// b) The pointer is not null.
// c) 0
// d) Error


#include <iostream>

int main() {
    const int number = 42;
    const int* ptr = &number;

    std::cout << *ptr << std::endl;

    return 0;
}

// What is the output of this program?
// a) 42
// b) &number
// c) The address of number
// d) Error


#include <iostream>

int main() {
    int value = 30;
    const int* const ptr = &value;

    std::cout << *ptr << std::endl;

    return 0;
}

// What is the output of this program?
// a) 30
// b) &value
// c) The address of value
// d) Error