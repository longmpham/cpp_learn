/*
Write a function to output a list of parsed values from the input. Include
all the support functions (ie link list) as well:

    Input:  1. Buffer that holds the input message
            2. Length of the message in bytes

    Output: Linked list that holds the parsed values. Each node
            should hold one of the following values:
                  Speed in km/h
                  Heading in degrees
                  Altitude in meters

    Return: 0       - if failed
            1       - if successful

    Message format:
            Values are stored in Big Endian notation.

            Byte 1 - 2:  Message Header (0x0508)
            Byte 3 - 4:  Speed Value in m/s
            Byte 5 - 6:  Heading Value in degrees
            Byte 7 - 8:  Altitude Value in cm
            Byte 9 - 10: Checksum

            1. Checksum is a binary addition of bytes from 3 to 8
            2. Message header must be checked
            3. Speed, heading, altitude are all unsigned integers.
*/

/*
1. Create a LinkedList to hold parsed messages ( 2 bytes ) of fixed length (5 nodes, 1 is header, 1 is checksum, 3 is body
2. Create a function to take bytes and size of bytes in as input (size = 5). Can fake this as an array of strings {"1234567890", "1234567890", "1234567890", "1234567890", "1234567890", }

*/

#include <iostream>

std::string storeMessage(std::string message, int size);
int checksum(std::string message, int size);
bool checkHeader(std::string message, int size);

int main(){

    // std::string myBuffer = {"0508010203", "0508020304", "0508030405", "0508040506", "0508050607"};
    std::string myBuffer = {"05080102030508020304050803040505080405060508050607"}; // look for the header
    int size = 5;
    std::string completedMessages[5]; // convert this to a LinkedList after.

    // Parse the messages.
    std::string messages = storeMessage(myBuffer, size); 


    return 0;
}

std::string storeMessage(std::string message, int size){

    // Create a LinkedList to hold new messages; for now, just use a array of strings

    // check buffer for header (0x0508)
    // if(checkHeader(message) == true) {

    // }


    return "";
}
int checksum(std::string message, int size){
    return 0;
}
bool checkHeader(std::string message, int size){
    return true;
}