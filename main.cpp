#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
};

class LinkedList {
    public:
        Node* head;
        
        // Constructor to create a linked list
        LinkedList() {
            head = NULL;
        }

        // Check if the linked list is empty
        bool isempty() {
            return (head == NULL);
        }

        void display()
        {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }

         int count()
        {
            int counter;
            Node* temp = head;
            while (temp != NULL) {
                counter++;
                temp = temp->next;
            }
            return counter;
        }

        bool isfound(int key)
        {
            bool found = false;
            Node* temp = head;
            while (temp != NULL) {
                if (temp->value == key) 
                    found = true;
                temp = temp->next;
                }
                   return false;  
        }


        // Insert a node at the beginning of the linked list
        void InsertFirst(int newvalue) {
            Node* newnode = new Node();              // Allocate memory for the new node
            newnode->value = newvalue;               // Set the node's value

            if (isempty()) {            
                newnode->next = NULL;                // If the list is empty, the next pointer should be NULL
                head = newnode;                      // The new node becomes the head of the list
            } else {            
                newnode->next = head;                // Otherwise, the new node points to the current head
                head = newnode;                      // And the new node becomes the new head
            }
        }
};

int main() {
    LinkedList list1 ;
    if(list1.isempty())
      cout<<"The List is Empty: "<<endl;
      else
       cout<<"The List contains: "<<list1.count()<<endl;

    int item;
    cout<<"Enter Item to insert in the List : "<<endl;
    cin>>item;
    list1.InsertFirst(item);
    list1.display();

    cout<<"Enter Item to insert in the List : "<<endl;
    cin>>item;
    list1.InsertFirst(item);
    list1.display();

    cout<<"Enter Item to insert in the List : "<<endl;
    cin>>item;
    list1.InsertFirst(item);
    list1.display();

    cout<<"The List contains: "<<list1.count() <<endl;

    cout<<"Enter Item to search for: "<<endl;
    cin >> item;
    if (list1.isfound(item))
     cout<<"Item found in the List"<<endl;
    else
     cout<<"Item not found in the List"<<endl;

    return 0;
}   
