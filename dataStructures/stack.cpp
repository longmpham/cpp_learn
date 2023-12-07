#include <iostream>
using namespace std;

class myStack
{
  private:
    int *startPointer;
    int theStack [10] = {0};
    int stackSize;
    
  public:
    myStack(int size) {
      startPointer = theStack;
      stackSize = size;
    }

    void appendToStack(int number)
    {
      int *temp = startPointer;
      while (*temp != 0)
      {
        temp++;
      }
      *temp = number;
      printStack();
    }
    void removeFromStack()
    {
      int *temp = startPointer;
      while(*temp != 0)
      {
        temp++;
      }
      // temp is either at the end or the stack is full. In either case, subtract temp
      // pointer location by 1 and make it 0 to "remove" the item from the stack
      temp--;
      *temp = 0;
      // can also become *--temp = 0; for one line.
    }
    void searchStack(int number)
    {
      int *temp = startPointer;
      int index = 0;
      while(*temp != number)
      {
        index++;
        temp++;
      }
      if (index < stackSize)
      {
        cout << "You found the number " << *temp << " in the stack! " << endl;
      }
      else
      {
        cout << number << " was not found" << endl;
      }
    }

    void printStack()
    {

      cout << "Using array subscript..." << endl;        
      for(int i = 0; i < stackSize; i++)
      {
        cout << theStack[i] << " ";        
      }
      cout << endl;
      cout << "Using pointer arithmetic..." << endl;        
      int *temp = startPointer;
      for(int i = 0; i < stackSize; i++)
      {
        cout << *(temp + i) << " ";
      }
      cout << endl;
    }

    ~myStack()
    {
      // delete [] theStack; 
    }
};


class myStackDynamic
{

  private:
    int *startPointer;
    int *myStack;
    int stackSize;
  public:

    myStackDynamic(int size)
    {
      stackSize = size;
      myStack = new int[stackSize];
      startPointer = myStack;
    }

    void appendToStack(int number)
    {
      
    }

    void removeFromStack()
    {

    }

    void searchStack(int number)
    {

    }

    void printStack()
    {

    }

    ~myStackDynamic()
    {

    }
};


int main()
{
  // to create a stack we should populate an array of size 10 for now.
  // create a pointer that points to the bottom of the array
  // create a function that appends to the stack (add)
  // create a function that pops from the stack (remove)
  // create a function that searches the stack for an element.
  // dont forget your constructor and destructor.
  // Todo: create a stack with dynamic array size (init with size x)

  myStack stk = myStack(10);

  stk.appendToStack(1);
  stk.appendToStack(2);
  stk.appendToStack(3);
  stk.appendToStack(4);
  stk.appendToStack(5);
  stk.appendToStack(6);
  stk.appendToStack(7);
  stk.appendToStack(8);
  stk.removeFromStack();
  stk.printStack();
  stk.searchStack(5);
  stk.searchStack(11);

  return 0;
}