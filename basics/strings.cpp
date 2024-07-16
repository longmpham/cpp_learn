#include <iostream>
#include <string>

int theBasics()
{
  std::string myString;

  myString = "hello world";

  std::cout << myString << std::endl; 

  // std::cin >> myString; // takes only 1 argument (no spaces!)
  std::getline(std::cin, myString);

  std::cout << "Hey " << myString << std::endl; 

  std::cin >> myString;

  std::cout << "Yo " << myString << std::endl; 


  return 0;
}

int stringsAndChars() 
{
  std::string str = "Hello, C++!";

  // Get the length of the string
  std::cout << "Length of the string: " << str.length() << std::endl;

  // Access characters in the string
  char firstChar = str[0];
  char lastChar = str[str.length() - 1];

  std::cout << "First character: " << firstChar << std::endl;
  std::cout << "Last character: " << lastChar << std::endl;

  return 0;
}

int reverseString()
{
  std::string str = "reverse me";

  std::cout << str << " is of length: " << str.length() << std::endl;


  std::string reversed = "";
  for (int i = str.length()-1; i >= 0; i--)
  {
    reversed += str[i];
  }

  std::cout << reversed << " is of length: " << reversed.length() << std::endl;
  return 0;
}

int reverseStringInPlace(std::string str)
{
  int first = 0;
  int last = str.length() - 1;
  std::cout << "Original: " << str << std::endl;
  while (first < last)
  {
    // std::swap(str[first], str[last]);
    // build your own swap.
    int temp = str[first];
    str[first] = str[last];
    str[last] = temp;
    
    first++;
    last--;
  }
  std::cout << "Reversed: " << str << std::endl;
}

int subStrings()
{
  std::string str = "Hello, C++!";
  std::cout << str << " is size: " << str.length() << std::endl;

  // Extracting a substring
  std::string sub = str.substr(7, 3); // Starting at index 7, take 3 characters

  std::cout << "Substring: " << sub << std::endl;


  return 0;
}


int main() {
    std::string sentence = "This is a C++ string.";

    // Find the position of a substring
    size_t found = sentence.find("C++");

    if (found != std::string::npos) {
        std::cout << "Substring found at position: " << found << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}