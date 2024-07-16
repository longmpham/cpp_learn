#include <iostream>

struct Node {
    int data;
    Node *next;

    Node(int value): data(value), next(nullptr){}
};

class LinkedList{
    private: Node *head;
    public:
        // Constructor
        LinkedList() : head(nullptr) {};

        void append(int value) {
            // start at the head, and go until your pointer reaches nullptr. When nullptr hits, 
            // thats where you append your new node

            // Create your node
            Node *newNode = new Node(value);
            if(head == nullptr){
                // its the very first one...
                head = newNode;
            } else {
                Node *tempNode = head;
                while(tempNode->next != nullptr){
                    tempNode = tempNode->next;
                }
                // finally, it will arrive when it finds nullptr
                tempNode -> next = newNode;
            }
            std::cout << "added " << value << std::endl;
        }

        bool search(int search){
            if(head == nullptr) return false;

            int index = 0;
            Node *tempNode = head;
            while(tempNode->next != nullptr){
                if(tempNode->data == search){
                    std::cout << search << " was found at index: " << index << std::endl;
                    return true;
                } else{
                    index++;
                    tempNode = tempNode->next;
                }
            }
            // didnt find anything and reached nullptr
            return false;
        }

        void insert(int value, int index){
            Node *newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                
            } else if (index == 0 && head != nullptr) {
                // insert on the first element (head)
                newNode->next = head;
                head = newNode;
            } else {
                // find the index
                Node *temp = head;
                int i = 0;
                while (temp-> next != nullptr && i < index - 1){
                    i++;
                    temp = temp->next;
                    std::cout << "not found yet: " << temp->data << " " << std::endl;
                }
                newNode -> next = temp -> next;
                temp->next = newNode;
            }
        }

        void display(){
            if (head == nullptr){
                std::cout << "nothing to show!" << std::endl;
            }
            else {
                Node *tempNode = head;
                while (tempNode != nullptr){
                    std::cout << tempNode->data << " ";
                    tempNode = tempNode->next;
                } 
                std::cout << std::endl;
            }
        }
};


int main() 
{
  LinkedList ll;

  ll.display();
  ll.append(1);
  ll.append(2);
  ll.append(3);
  ll.display(); // 1 2 3
  ll.append(4);
  ll.append(5);
  ll.display(); // 1 2 3 4 5
  ll.search(4); // 4 is at index 3
  ll.insert(6,5); // adds 6 at index 5, which is the end

  ll.display();

  return 0;

}