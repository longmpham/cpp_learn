#include <iostream>

using namespace std;

int main(){

    string questions[] = {
        "1. What year was C++ created?: ",
        "2. What is the predecessor to C++?: ",
        "3. Who invented C++?: ",
        "4. Is the Earth flat?: ",
    }; 

    string options [][4] = {
        {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
        {"A. Guido Van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerberg"},
        {"A. C", "B. C+", "C. C", "D. C#"},
        {"A. Yes", "B. No", "C. Sometimes", "D. What's Earth!?"},
    };

    char answerKey [] = {'C', 'B', 'A', 'B'};

    int size = sizeof(questions)/sizeof(questions[0]);
    char guess;
    int score;

    for (int i = 0; i < size; i++){
        cout << questions[i] << endl;
        for (int j = 0; j < size; j++){
            cout << options[i][j] << endl;
        }
        cout << "Your answer: ";
        cin >> guess;
        score++;
    }

    cout << "Your score is: " << score << " out of " << size << endl;

    return 0;
}