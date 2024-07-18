/*
Write a function to output a list of parsed values from the input. Include
all the support functions (ie link list) as well:

    Input:  1. Buffer that holds the input message                  done 
            2. Length of the message in bytes                       done

    Output: Linked list that holds the parsed values. Each node     done
            should hold one of the following values:
                  Speed in km/h                                     done
                  Heading in degrees                                done
                  Altitude in meters                                done

    Return: 0       - if failed                                     done 
            1       - if successful                                 done

    Message format:
            Values are stored in Big Endian notation.

            Byte 1 - 2:  Message Header (0x0508)
            Byte 3 - 4:  Speed Value in m/s
            Byte 5 - 6:  Heading Value in degrees
            Byte 7 - 8:  Altitude Value in cm
            Byte 9 - 10: Checksum

            1. Checksum is a binary addition of bytes from 3 to 8   done
            2. Message header must be checked                       done
            3. Speed, heading, altitude are all unsigned integers.  done
*/

/*
    This is my 3rd iteration which started from string inputs to string outputs.
    In this revision I have changed the data types to match the output requested from above.
    I grabbed string to <num> converters from the internet, couldnt find a native way to do it myself.
*/



#include <iostream>
#include <string> // for stoi()
#include <cstdint>
#include <cstdio>  // For sprintf
#include <regex>

// Helper function to convert back to hex (grabbed from internet)
std::string uint16ToHexString(uint16_t value);
uint16_t hexStringToUInt16(const std::string &hexStr);
std::string calculateChecksum(std::string speed, std::string altitude, std::string heading);
std::string convertToHexadecimal (int unit);
int convertToDecimal (std::string unit);
// create my own linkedlist
struct Node {
    uint16_t data;
    Node *next;

    Node(uint16_t value) : data(value), next(nullptr){} 
};

class MyLinkedList {
    private: Node *head;
    public:
        MyLinkedList() : head(nullptr) {}
        // append message
        void append(uint16_t value){
            // check if head is empty
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
            } else {
                Node *temp = head;
                while (temp->next != nullptr){
                    // keep moving until we find a nullptr
                    temp = temp->next;
                }
                // found a nullptr now enter your value.
                temp->next = newNode;
            }
        }

        // print message
        void print(){

            if (head == nullptr){
                std::cout << "Message is empty and cannot be printed! \n";
                return;
            }
            Node *temp = head;
            std::cout << "Message Output: ";
            while(temp != nullptr){
                // print data and then go to the next node
                std::cout << uint16ToHexString(temp->data) << " ";
                temp = temp->next;
            }
            std::cout << '\n';
        }
};

// normal functions required
int storeMessage(std::string message, int size, MyLinkedList &messageWithChecksum);

int main(){

    // assumption: 1 message input;
    std::string myBuffer = "0508010203"; // base case ->                                valid
    // std::string myBuffer = "zz010203ab"; // regex case ->                               invalid
    // std::string myBuffer = "050220508222"; // extra data, incomplete sentence ->     invalid
    // std::string myBuffer = "020508220508222"; // extra data, complete sentence ->    valid
    // std::string myBuffer = "0500508"; // too short ->                                invalid
    // std::string myBuffer = "050220508"; // look for the header at the end ->         invalid
    // std::string myBuffer = ""; // empty ->                                           invalid
    // std::string myBuffer = "0011223344"; // string is 10, but no header found  ->    invalid
    int size = myBuffer.size();
    MyLinkedList messageWithChecksum;

    // Prase the messages (this is the function requested to write) which returns 0 for bad msg or 1 for good msg
    int validMessage = storeMessage(myBuffer, size, messageWithChecksum); 

    // is the message valid?
    messageWithChecksum.print();
    std::cout << (validMessage == 1 ? "Message is valid (1)" : "Message is invalid (0)") << '\n';

    return 0;
}

int storeMessage(std::string message, int size, MyLinkedList &messageWithChecksum){

    std::string header = "0508";
    std::string speed;
    std::string altitude;
    std::string heading;
    int indexStart = 0;

    // check if empty message
    if (message.size() <= 0){
        std::cout << "Message is empty\n";
        return 0;
    }
    // Check for a valid sequence of hexadecimals
    std::regex hex_regex("^[0-9a-fA-F]+$");
    if (!regex_match(message, hex_regex)){
        std::cout << "Message is not hexadecimal!\n";
        return 0;
    }
    // check the header in the beginning
    if (message.substr(0, 4) != header && message.length() == 10) {
        std::cout << "Start of message does not contain header\n";
        return 0;
    // check the size too short
    } else if (message.size() < 10) {
        std::cout << "Message is too short (not even 10 bytes!)\n";
        return 0;
    // there is another case where the message is greater than 10 bytes and the message can be of length 10 anywhere in the buffer.
    } else if (message.size() > 10) {
        // make a sliding window to check for the header
        for (int i = 0; i < size; i++){
            if (message.substr(i,4) == "0508"){
                // if the message has a header but is short... we can handle that here
                if (i + 10 > size){
                    std::cout << "Message contains header, but message is incomplete\n";
                    return 0;
                }
                indexStart = i;
                // otherwise, the message is of length 10 and has a header 0508
                break;
            }
        }
    }
    // We're expecting bytes of exactly 10 from here on in.
    speed = message.substr(indexStart+4, 2);
    altitude = message.substr(indexStart+6, 2);
    heading = message.substr(indexStart+8, 2);
    // std::cout << "DEBUG::: " << speed << " " << altitude << " " << heading << " " << std::endl;
    
    // calculate the checksum of this message
    std::string checksum = calculateChecksum(speed, altitude, heading);

    // messageWithChecksum = header+speed+altitude+heading+checksum;
    // assumption: uint16_t vs unsigned int: I used uint16_t because I figured each field was 2 bytes (except for the header)
    // but the header is split anyways into two uint16_t variables. That way I would save space/memory (16-bit vs 32-bit)
    uint16_t byteHeader1 = hexStringToUInt16(header.substr(0, 2));
    uint16_t byteHeader2 = hexStringToUInt16(header.substr(2, 2));
    uint16_t byteSpeed = hexStringToUInt16(speed);
    uint16_t byteAltitude = hexStringToUInt16(altitude);
    uint16_t byteHeading = hexStringToUInt16(heading);
    uint16_t byteChecksum = hexStringToUInt16(checksum);

    // I can simplify the append to just include the converting function above but this is more clear on whats happening i hope
    messageWithChecksum.append(byteHeader1);
    messageWithChecksum.append(byteHeader2);
    messageWithChecksum.append(byteSpeed);
    messageWithChecksum.append(byteAltitude);
    messageWithChecksum.append(byteHeading);
    messageWithChecksum.append(byteChecksum);

    return 1;
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

int convertToDecimal (std::string unit){
    int converted = std::stoi(unit, 0, 16); // can minimize function to just the return statement to save space
    return converted;
}

std::string convertToHexadecimal (int unit){
    std::string hexString = std::to_string(unit); // can minimize function to just the return statement to save space
    return hexString;
}

// Function to format a uint16_t value as a hexadecimal string using sprintf (from internet thankfully!)
uint16_t hexStringToUInt16(const std::string &hexStr) {
    return static_cast<uint16_t>(std::stoi(hexStr, nullptr, 16));
}

std::string uint16ToHexString(uint16_t value) {
    char buffer[3];  // 2 digits + 1 null terminator
    std::sprintf(buffer, "%02x", value);
    return std::string(buffer);
}