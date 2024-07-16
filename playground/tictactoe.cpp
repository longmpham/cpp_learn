#include <iostream>
#include <ctime>

using namespace std;

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            break;
        }
        computerMove(spaces,computer);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer)){
            running = false;
            cout << "You win!\n";
            break;
        }

        // check if all spaces are filled and call a tie.
        if(checkTie(spaces)){
            cout << "Its a draw!\n";
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces){
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    cout << "_____|_____|_____" << '\n';
    cout << "     |     |     " << '\n';
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    cout << "     |     |     " << '\n';
}

void playerMove(char *spaces, char player){
    int number;
    do{
        cout << "Enter user marker (1-8): ";
        cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
        else {
            cout << "Spot taken!\n";
        }

    } while(!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer){
    int number;
    srand(time(0)); // generate random time seed
    while(true){
        number = rand() % 9; // generate number from 0 to 8
        if(spaces[number] == ' ') {
            spaces[number] = computer;
            break;
        }
    }

}

bool checkWinner(char *spaces, char player, char computer){

    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        spaces[0] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        spaces[3] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        spaces[6] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        spaces[0] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        spaces[1] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        spaces[2] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        spaces[0] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        spaces[2] == player ? cout << "Winner!" : cout << "Loser!\n";
    }
    else {
        return false;
    }
}

bool checkTie(char *spaces){
    for (int i = 0; i < 8; i++){
        if (spaces[i] == ' '){
            return false;
        }
    }
    return true;
}