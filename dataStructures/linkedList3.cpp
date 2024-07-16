#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int value): data(value), next(nullptr){}
};

class LinkedList{
  private: 
    Node *head;
  public:
    LinkedList() : head(nullptr) {}
    // create append, insert, delete, search, and show/print

    void append(int value){
      Node *newNode = new Node(value);
      if (head == nullptr){
        // there is no list to start so create the head
        head = newNode;
      }
      else {
        Node *temp = head;
        while(temp->next != nullptr){
          temp = temp->next;
        }
        temp -> next = newNode;
      }
    }

    void insert(int value, int index){
      // case 1: head
      Node *newNode = new Node(value);
      if(head == nullptr){
        head = newNode;
      // case 2: add at the head
      } else if(index == 0 && head != nullptr){
        newNode->next = head;
        head = newNode;
      // case 3: add after the head
      } else{
        Node *temp = head;
        int i = 0;
        while(temp->next != nullptr && i < index-1){
          i++;
          temp = temp->next;
          cout << "not found yet: " << temp->data << " " << endl;
        }
        newNode->next = temp->next;
        temp->next = newNode;
      }

    }

    bool search(int value){
      if (head == nullptr){
        return false;
      }
      Node *temp = head;
      int index = 0;
      while(temp->next != nullptr){
        if (temp->data == value){
          cout << value << " was found at index: " << index << endl;
          return true;
        }
        else{
          index++;
          temp = temp->next;
        }
      }
      cout << value << " was not found" << endl;
      return false;
    }

    void display(){

      if (head == nullptr){
        cout << "nothing to print out" << endl;
      }else{
        Node *temp = head;
        while(temp != nullptr){
          cout << temp->data << " ";
          temp = temp->next;
        }
        cout << endl;
      }
    }
};

int main() 
{
  LinkedList ll;

  ll.display(); // nothing
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.display(); // 1 2 3
  ll.append(4);
  ll.append(5);
  ll.display(); // 1 2 3 4 5
  ll.search(4); // 4 is at index 3
  ll.insert(5,4); // adds 6 at index 5, which is the end

  ll.display();

  return 0;

}