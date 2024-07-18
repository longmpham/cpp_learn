/*
Write a function to output a list of parsed values from the input. Include
all the support functions (ie link list) as well:

    Input:  1. Buffer that holds the input message -> done? 
            2. Length of the message in bytes -> done?

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
#include <string> // for stoi()

std::string storeMessage(std::string message, int size);
int checksum(std::string message, int size);
bool checkHeader(std::string message, int size);
std::string calculateChecksum(std::string speed, std::string altitude, std::string heading);
std::string convertToHexadecimal (int unit);
int convertToDecimal (std::string unit);
int isValid(std::string);

int main(){

    // assumption: its not just 1 message coming in so I've created a "buffer" to look for messages
    // std::string myBuffer = {"0508010203", "0508020304", "0508030405", "0508040506", "0508050607"};
    std::string myBuffer = "05080102030508020304050803040505080405060508050607"; // look for the header
    // std::string myBuffer = {"05d0801020305d0802030405080304a0505080405060d50d8050607"}; // look for the header
    int size = myBuffer.size();
    std::cout << "the size is " << size << std::endl;
    // int size = 25; //25 bytes -> message is 50 chars / 2 = 25
    std::string completedMessages[5]; // convert this to a LinkedList after.

    // Parse the messages.
    std::string messages = storeMessage(myBuffer, size); 
    int validMessage = isValid(messages);
    std::cout << (validMessage == 1 ? "Message is valid" : "Message is invalid") << '\n';

    return 0;
}
int isValid(std::string str){
    std::cout << "num of messages = " << str.size() << '\n';
    if (str.length() > 0) return 1;
    
    return 0;
}
std::string storeMessage(std::string message, int size){

    // Create a LinkedList to hold new messages; for now, just use an array of strings

    // check buffer for header (0x0508)

    std::string header = "0508";
    std::string speed;
    std::string altitude;
    std::string heading;
    std::string messages[5]; // change to linkedlist later

    int messageCounter = 0;
    for (int i = 0; i < size; i++){
        std::cout << "DEBUG: i= " << i << " and i+4= " << message.substr(i,4) << "\n";
        if (i+4 >= size) break; 
        // create a sliding window to check for 0508
        // if (message[i] == '0' && message[i+1] == '5' && message[i+2] == '0' && message[i+3] == '5'){
        if (message.substr(i, 4) == header) {
            // header matches. speed = i+4,5 alt = i+6,7, hdg = i+8,9 (assumption is we're guaranteed the message given the header)
            speed = message.substr(i+4, 2);
            altitude = message.substr(i+6, 2);
            heading = message.substr(i+8, 2);
            // std::cout << speed << " " << altitude << " " << heading << " " << std::endl;
            
            // calculate the checksum of this message
            std::string checksum = calculateChecksum(speed, altitude, heading);
            // add the message to the messages array

            // store message here to LL (currently a string array)
            messages[messageCounter] = header+speed+altitude+heading+checksum; 
            std::cout << messages[messageCounter++] << std::endl;

            // clean up -> i header was found so add 10 for the next message
            i = i + 9;
        }
        else {
            // std::cout << "potentially corrupt message" << std::endl;
        }
    }



    return "";
}

int convertToDecimal (std::string unit){
    int converted = std::stoi(unit, 0, 16); // can minimize function to just the return statement to save space
    return converted;
}

std::string convertToHexadecimal (int unit){
    std::string hexString = std::to_string(unit); // can minimize function to just the return statement to save space
    return hexString;
}

std::string calculateChecksum(std::string speed, std::string altitude, std::string heading){
    int checksum = convertToDecimal(speed) + convertToDecimal(altitude) + convertToDecimal(heading);
    std::string checksumStr = convertToHexadecimal(checksum);

    // check for overflow:
    if (checksumStr.length() > 2) {
        checksumStr = checksumStr.substr(checksumStr.length() - 2);
    } else if (checksumStr.length() == 1) {
        // check for single digits and pad with 0
        checksumStr = "0" + checksumStr;
    }
    return checksumStr;
}

bool checkHeader(std::string message, int size){
    return true;
}