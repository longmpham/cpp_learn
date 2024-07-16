#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()


char getUserInput();
char getComputerInput();
bool compute(char user, char computer);
char playAgain();

int main(){
    // create a rock paper scisccors game!
    char play;
    do{

        char user = getUserInput();

        char computer = getComputerInput();
        

        bool result = compute(user,computer);

        std::cout << "my choice: " << user << " ||| computers choice: " << computer << std::endl;
        std::cout << (result ? "You Win!" : "You Lose!") << std::endl;

        play = playAgain();
    } while (play == 'y');
}

bool compute(char user, char computer){

    if(user == computer) return false;
    if((user == 'r' && computer == 's') ||
        (user == 'p' && computer == 'r') || 
        (user == 's' && computer == 'p')) return true;
    return false;
}
char playAgain(){

    char user;
    do{

        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> user;
    } while (user != 'y' && user != 'n');
    return user;
}
char getComputerInput(){
    // use rand to get a number between 1 2 3 where 1 = rock, 2 = paper, 3 = scissor
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // seed random time
    char charSelection;
    int randomNumber = (std::rand() % 3) + 1;
    if (randomNumber == 1) charSelection = 'r';
    else if (randomNumber == 2) charSelection = 'p';
    else charSelection = 's';
    return charSelection;
}
char getUserInput()
{
    char userChoice;

    do
    {
        std::cout << "Choose one of the following:" << std::endl;
        std::cout << "r = rock, p = paper, s = scisscors, q to quit: ";
        std::cin >> userChoice;

    } while (userChoice != 'q' && userChoice != 'r' && userChoice != 'p' && userChoice != 's');
    if (userChoice == 'q') {
        std::cout << "Goobyeeee" << std::endl;
        exit(0);
    }
    return userChoice;
}