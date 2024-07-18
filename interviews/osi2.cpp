/*
Write a function to output a list of parsed values from the input. Include
all the support functions (ie link list) as well:

    Input:  1. Buffer that holds the input message ->               done 
            2. Length of the message in bytes ->                    done

    Output: Linked list that holds the parsed values. Each node     not done
            should hold one of the following values:
                  Speed in km/h                                     not done
                  Heading in degrees                                not done
                  Altitude in meters                                not done

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
            3. Speed, heading, altitude are all unsigned integers.  not done
*/

/*
1. Create a LinkedList to hold parsed messages ( 2 bytes ) of fixed length (5 nodes, 1 is header, 1 is checksum, 3 is body
2. Create a function to take bytes and size of bytes in as input (size = 5). Can fake this as an array of strings {"1234567890", "1234567890", "1234567890", "1234567890", "1234567890", }

*/

#include <iostream>
#include <string> // for stoi()

int storeMessage(std::string message, int size, std::string &messageWithChecksum);
std::string calculateChecksum(std::string speed, std::string altitude, std::string heading);
std::string convertToHexadecimal (int unit);
int convertToDecimal (std::string unit);

int main(){

    // assumption: 1 message input
    // std::string myBuffer = {"0508010203", "0508020304", "0508030405", "0508040506", "0508050607"};
    std::string myBuffer = "05080102031"; // look for the header
    int size = myBuffer.size();
    std::string messageWithChecksum;

    // Parse the messages.
    int validMessage = storeMessage(myBuffer, size, messageWithChecksum); 
    std::cout << "Final message: " << messageWithChecksum << '\n';

    std::cout << (validMessage == 1 ? "Message is valid" : "Message is invalid") << '\n';

    return 0;
}

int storeMessage(std::string message, int size, std::string &messageWithChecksum){

    // Create a LinkedList to hold new messages; for now, just use an array of strings

    // check buffer for header (0x0508)

    std::string header = "0508";
    std::string speed;
    std::string altitude;
    std::string heading;

    int indexStart = 0;
    // check the header
    if (message.substr(0, 4) != header) {
        return 0;
    // check the size
    } else if (message.size() <= 10) {
        return 0;
    // there is another case where the message is greater than 10 bytes and the message can be of length 10 anywhere in the buffer.
    } else if (message.size() > 10) {
        // make a sliding window to check for the header
        for (int i = 0; i < size; i++){
            if (message.substr(i,4) == "0508"){
                // if the message has a header but is short... we can handle that here
                if (i + 10 > size){
                    return 0;
                }
                indexStart = i;
                // otherwise, the message is of length 10 and has a header 0508
                break;
            }
        }
    }
    // We're expecting bytes of 10 from here on in.

    speed = message.substr(indexStart+4, 2);
    altitude = message.substr(indexStart+6, 2);
    heading = message.substr(indexStart+8, 2);
    // std::cout << "DEBUG::: " << speed << " " << altitude << " " << heading << " " << std::endl;
    
    // calculate the checksum of this message
    std::string checksum = calculateChecksum(speed, altitude, heading);

    // store message here to LL (currently a string)
    messageWithChecksum = header+speed+altitude+heading+checksum; 
    std::cout << messageWithChecksum << '\n';

    return 1;
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