#include <iostream>
#include <vector>

int main(){

    char choice {};
    std::vector<int> vec {1,2,34,5,2,23,452,521,55,9,10};
    bool isQuit {false};

    do {
        std::cout << "\nSelect a choice [p,a,m,s,l,q]:\n";
        std::cin >> choice;
        switch(choice){
            case 'p':
            {
                std::cout << "Printing all numbers in the list:\n";
                for (auto num : vec){
                    std::cout << num << " ";
                }
                break;
            }
            case 'a':
            {
                std::cout << "Adding a number to the list: ";
                int input {0};
                std::cin >> input;
                vec.push_back(input);
                break;
            }
            case 'm':
            {
                std::cout << "Take the mean of all numbers in the list:\n";
                double mean {};
                for (auto num : vec){
                    mean += num;
                }
                std::cout << mean/vec.size() << '\n';
                break;
            }
            case 's':
            {
                std::cout << "Print the smallest number in the list:\n";
                int smallest = vec.at(0);
                for (auto num : vec){
                    if (num < smallest){
                        smallest = num;
                    }
                }
                std::cout << smallest << '\n';
                break;
            }
            case 'l':
            {
                std::cout << "Print the largest number in the list:\n";
                int largest = vec.at(0);
                for (auto num : vec){
                    if (num > largest){
                        largest = num;
                    }
                }
                std::cout << largest << '\n';
                break;   
            }
            case 'q':
            {
                std::cout << "Quitting:\n";
                isQuit = true;
                break;
            }
            default: 
                std::cout << "Not a valid choice\n";
        }
    } while (!isQuit);
}