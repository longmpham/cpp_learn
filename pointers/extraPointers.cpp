#include <iostream>


void print(char *C){
    while(*C != '\0'){
        std::cout << *C << " ";
        C++;
    }
}

int main() {

    char C[20] = "Hello";

    print(C);

    return 0;

}