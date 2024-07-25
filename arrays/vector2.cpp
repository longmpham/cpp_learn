#include <iostream>
#include <vector>

int main() {

    std::vector<int> vec1;
    std::vector<int> vec2;

    for(int i = 0; i < 10; i++){
        vec1.push_back(i);
        vec2.push_back(i+10);
    }

    std::cout << "Vec1: ";
    for(int i = 0; i < vec1.size(); i++){
        std::cout << vec1.at(i) << " ";
    }
    std::cout << "\nVec2: ";
    for(int i = 0; i < vec2.size(); i++){
        std::cout << vec2.at(i) << " ";
    }


    return 0;
}