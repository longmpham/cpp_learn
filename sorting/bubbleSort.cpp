#include <iostream>
using namespace std;

void mySwap(int *p1, int *p2);

int main() 
{
  // 1. we initialize an array of numbers
  // 2. we sort ascending (least to greatest)
  // 3. Use 2 pointers and compare. If pointer 1 (first) is less or equal 
  //    than pointer 2 then move on. if pointer 1 is greater
  //    then swap
  // 4. Create a swap function
  // 5. if no swaps occur on an iteration, the array is sorted.

  int randomArray [] = {7,6,5,4,3,2,5,3,2,1};
  // int n = sizeof(randomArray) / sizeof(randomArray[0]); // old C way of getting the size of the array
  int n = size(randomArray); // new C++11 way of getting size of the array

  bool swapped;
  for (int i = 0; i < n - 1; i++)
  {
    // for a fast check, if no swaps occur on the first pass, the array is sorted and we can return
    swapped = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      int *p1 = &randomArray[j];    
      int *p2 = &randomArray[j + 1];
      if(*p1 > *p2)
      { 
        mySwap(p1, p2);
        swapped = true;
      }
    }
    // check here if any swaps were made, and if not, its sorted!
    if(swapped == false)
    {
      break;
    }
  }

  for (int i = 0; i < n; i++)
    std::cout << randomArray[i] << " ";
  std::cout << "\n";


  return 0;
}


void mySwap(int *p1, int *p2)
{
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  return;
}