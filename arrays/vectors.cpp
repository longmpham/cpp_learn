#include <iostream>
#include <vector>

int main() {

    std::vector <int> myNumbers {1,2,3,4,5,6,7,8,9};

    for (auto i : myNumbers){
        std::cout << i << " ";
    }
    std:: cout << '\n';

    // // to get the length of vector
    std::cout << "The number of elements in the vector: " << myNumbers.size() << '\n';

    // // to add to the vector at the end
    myNumbers.push_back(10);
    std::cout << "Added a 10!\n";
    for (auto i : myNumbers){
        std::cout << i << '\n';
    }

    return 0;

}