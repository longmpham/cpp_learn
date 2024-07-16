#include <iostream>

using namespace std;

void sortBubbleArray(int myArr[], int size);

int main(){

    int myArr[] = {1,9,2,3,5,4,7,6,8};
    int size = sizeof(myArr) / sizeof(myArr[0]);
    // for (int i = 0; i < size; i++){
    //     for (int j = 0; j < size - 1; j++){
    //         if (myArr[j] > myArr[j+1]){
    //             int temp = myArr[j];
    //             myArr[j] = myArr[j+1];
    //             myArr[j+1] = temp;
    //         }
    //     }
    // }
    sortBubbleArray(myArr, size);

    for (int i = 0; i < size; i++){
        cout << myArr[i];
    }
    return 0;
}

void sortBubbleArray(int myArr[], int size){

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (myArr[j] > myArr[j+1]){
                int temp = myArr[j];
                myArr[j] = myArr[j+1];
                myArr[j+1] = temp;
            }
        }
    }

}