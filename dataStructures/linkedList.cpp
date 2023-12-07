#include <iostream>

// *******Member Initializer vs Body initialization
// Performance: The member initializer list allows for more efficient construction of objects. 
// It initializes members directly, often resulting in better performance than assigning values 
// in the constructor body.

// Order of Initialization: Member initializer lists specify the order in which members are 
// initialized. This is particularly important when dealing with class inheritance or when 
// members depend on each other. The order of initialization in the initializer list is the 
// order in which the members are declared in the class or struct definition.

// Constants and References: Certain types of members, such as constant members and 
// reference members, must be initialized in the member initializer list because they 
// cannot be assigned values in the constructor body.

// Readability and Consistency: Using a member initializer list can make the code more 
// readable and consistent, especially when dealing with multiple constructors or 
// complex initialization logic. It separates the initialization concerns from the 
// logic in the constructor body.

struct Node
{
  int data;
  Node *next;
  
  // Constructor//init
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList 
{
  private:
    Node *head;
  
  public:
    LinkedList() : head(nullptr) {}

    // using -> is usefull when accessing member variables of a struct.
    // temp -> next; is equivalent to head.next in Python
    // temp = temp -> next ======= temp = temp.next


    // to append, we need to find the next pointer where it is nullptr.
    // therefore we need to:
    // 1. Create a new Node with the value
    // 2. Create a temp pointer that starts at the head
    // 3. In a loop, check if temp pointer == nullptr
    // 4. if not true, temp pointer = temp pointer next
    // 5. if true, assign newNode to temp
    void append(int value)
    {
      Node *newNode = new Node(value);
      if (head == nullptr)
      {
        head = newNode;
      }
      else 
      {
        Node *temp = head;
        while (temp -> next != nullptr)
        {
          temp = temp -> next;
        }
        temp -> next = newNode;
      }
    }

    bool query(int query)
    {
      int index = 0;
      if (head == nullptr)
      {
        return false;
      }
      else 
      {
        Node *temp = head;
        while (temp -> next != nullptr)
        {
          if (temp -> data == query)
          {
            std::cout << temp -> data << " has been found at index: " << index << std::endl;
            return true;
          }
          else 
          {
            index++;
            temp = temp -> next;
          }
        }
        return false;
      }
    }


    // To insert at an index, we need to go to the index specified,
    // we need to reference the next pointer with a temp pointer
    // place the new value at the index
    // the new value needs to point to the next node
    void insert(int value, int index)
    {
      Node *newNode = new Node(value);
      if (head == nullptr && index == 0)
      {
        head = newNode;
      }
      else if (head != nullptr && index == 0)
      {
        // assign new nodex next as the head
        // reassign the head as the newNode
        newNode -> next = head;
        head = newNode;
      }
      else 
      {
        Node *temp = head;
        int i = 0;
        while (temp -> next != nullptr)
        {
          if (i == index - 1)
          {
            std::cout << "Found a spot at index: " << i << " with a value of: " << temp -> data << std::endl;
            Node *nextNode = temp -> next;
            temp -> next = newNode;
            newNode -> next = nextNode;

            return;
          }
          else
          {
            i++;
            temp = temp -> next;
          }
        }
        // If index is the last position (insert at the end)
        if (i + 1 == index) {
            temp->next = newNode;
        }
      }

    }

    void display() 
    {
      Node *temp = head;
      while (temp != nullptr)
      {
        std::cout << temp -> data << " ";
        temp = temp -> next;
      }
      std::cout << std::endl;
    }



    // Deconstructor!
    // create a temp that points at the head and as long as the temp != nullptr, we have to go through it
    // 1. if not nullptr, assign a pointer that points to the next pointer after temp
    // 2. delete temp
    // 3. assign temp the next node in line
    // 4. repeat 1-3
    // 5. finally, assign temp/head = nullptr
    ~LinkedList()
    {
      Node *temp = head;
      while (temp != nullptr)
      {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
      }
      head = nullptr;
    }
};

int main() 
{
  LinkedList ll;

  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.append(4);
  ll.append(5);
  ll.query(4);
  ll.insert(6,5);

  ll.display();

  return 0;

}