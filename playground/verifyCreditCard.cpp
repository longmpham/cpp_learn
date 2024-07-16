#include <iostream>

/*
Luhn Algo:
1. Double every second digit from right to left. If doubled number is 2 digits, split them (ie. 9 -> 18 -> 1 8)
2. Add all single digits from step 1
3. Add all odd numbered diits from right to left
4. Sum results from 2 & 3
5. If step 4 is divisible by 10, the card is VALID.
ex.
6011 0009 9013 9424
6 1  0 0  9 1  9 2
12 2 0 0  18 2 18 4
1 2 2 0 0 1 8 2 1 8 4 => take sum = 29

6011 0009 9013 9424
 0 1  0 9  0 3  4 4
no need to split (not in algo)
0 1 0 9 0 3 4 4 => take sum = 21

take sum of both steps 29 + 21 = 50 mod 10 = 0 => valid!
*/
int sumEvens (std::string cc, int size);
int sumOdds (std::string cc, int size);
int main(){

    std::string cc = "6011000990139424";
    int size = cc.size();
    std::cout << "size: " << size << std::endl;
    int evens[8];
    int odds[8];

    int evenSum = sumEvens(cc, size);
    int oddSum = sumOdds(cc, size);
    
    // finally, add odd and evens
    int totalSum = evenSum + oddSum;
    if (totalSum % 10 == 0) {
        // 6011 0009 9013 9424 valid
        std::cout << "The credit card is valid" << std::endl;
    }
    else{
        // 6011 0009 9013 9425 invalid
        std::cout << "The credit card is invalid" << std::endl;
    }
}

int sumEvens (std::string cc, int size){
    int evenSum = 0;
    for (int i = 0; i < size; i+=2){
        // std::cout << "Current Number: " << cc[i] << std::endl;
        int temp = cc[i] - '0';
        temp = temp * 2; // double the number
        int temp2 = 0;
        // std::cout<< "Temp * 2 is: " << temp << std::endl;
        if (temp >= 10){ // check the number if > 10
            // split the number into 2.
            temp2 = 1; // takes care of the first digit
            temp = temp%10; // takes care of second digit
            // std::cout << "temp1: " << temp << " temp2: " << temp2 << std::endl;

            // std::cout << "temp mod 10: " << temp << std::endl;
        }
        evenSum += temp + temp2;
    }
    std::cout << evenSum << std::endl;
    return evenSum;
}

int sumOdds (std::string cc, int size){
    int oddSum = 0;
    for (int i = 1; i < size; i+=2){
        oddSum += cc[i] - '0'; // convert to int
    }    
    std::cout << oddSum << std::endl;
    return oddSum;
}

void different_ways_to_convert_to_int(){
    std::string str = "54";
    int digit = atoi(&str[0]);
    
    std::string str = "54";
    int digit = str[0] - '0';

    std::string str = "54";
    int digit = str[0] - 48;

    std::string str = "54";
    // int digit = std::stoi(str[0]); // this dont work for whatever reason
}