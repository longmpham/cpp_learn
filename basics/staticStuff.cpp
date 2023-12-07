// 1. Static Variables

#include <iostream>

class MyClass {
public:
    static int staticVar;

    MyClass() {
        staticVar++;
    }
};

int MyClass::staticVar = 0;  // Initialization of the static variable

int main1() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    // output = 3
    std::cout << "Static variable value: " << MyClass::staticVar << std::endl;

    return 0;
}

// Static variables are variables that are shared among all instances 
// of a class or all calls to a function. They persist throughout the
// program's execution and are initialized only once. In this example, 
// staticVar is a static data member of the MyClass. All instances of 
// MyClass share the same staticVar. When you create multiple objects 
// of MyClass, the static variable is incremented for each object, 
// but there is only one instance of the variable.


// 2. Static Member Functions

#include <iostream>

class MathUtility {
public:
    static int add(int a, int b) {
        return a + b;
    }
};

int main2() {
    int result = MathUtility::add(3, 5);

    // Output = 8
    std::cout << "Result of addition: " << result << std::endl;

    return 0;
}

// Similar to static variables, static member functions belong to 
// the class rather than an instance of the class. They can be 
// called on the class itself, without creating an instance of 
// the class. Here, add is a static member function of the 
// MathUtility class. You can call it directly on the class 
// without creating an object.


// 3. Static Local Variables:

#include <iostream>

void counterFunction() {
    static int count = 0;  // Static local variable

    count++;
    std::cout << "Counter: " << count << std::endl;
}

int main() {
    counterFunction();
    counterFunction();
    counterFunction();

    return 0;
}

// Static local variables are used inside a function, and they retain 
// their values between function calls. They are initialized only once.
// In this example, count is a static local variable inside the 
// counterFunction(). It retains its value between function calls 
// and is initialized only once.