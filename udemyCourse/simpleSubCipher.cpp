#include <iostream>
#include <string>

int main(){

    std::string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string cipher {"CDEXYZabcdFGHIJklmfghnoRSTUVWepqrstOPQijuvwxyzABKLMN"};

    std::string input {};

    std::cout << "Enter your String you want to encrypt: ";
    std::cin >> input;

    // run the cipher;
    for (int i {0}; i < input.length(); i++){
        int index = alphabet.find(input[i]);
        input[i] = cipher[index];
    }
    std::cout << input << std::endl;

    // decode
    for (int i {0}; i < input.length(); i++){
        int index = cipher.find(input[i]);
        input[i] = alphabet[index];
    }
    std::cout << input << std::endl;

    return 0;
}