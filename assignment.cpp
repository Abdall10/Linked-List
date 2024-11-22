#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T value;          // Value can now be of any type
    Node* next = NULL; // Pointer to the next node
};

template <typename T>
class LinkedList {
private:
    Node<T>* head = NULL;

public:
    // Insert function
    void insertNode(T data) {
        Node<T>* newNode = new Node<T>; // Create a new node
        newNode->value = data;          // Assign value to the new node
        if (head == NULL) {
            head = newNode;
        } else {
            Node<T>* last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newNode;
        }
    }

    // Display function to display values of the linked list
    void display() const {
        if (isEmpty()) {
            cout << "Linked List is empty" << endl;
        } else {
            Node<T>* currentNode = head;
            while (currentNode != NULL) {
                cout << currentNode->value.first << " " << currentNode->value.second << endl;
                currentNode = currentNode->next;
            }
        }
    }

    // Function to check if the list is empty
    bool isEmpty() const {
        return head == NULL; // Return true if head is NULL
    }

    // Destructor to clean up the memory
    ~LinkedList() {
        Node<T>* current = head;
        while (current != NULL) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList<pair<int, string>> intList; // Linked list for integer-level and string-description pairs
    cout<<"Welcome to the C++ learning! \n";
    // Check if the list is empty
    if (intList.isEmpty()) {
        cout << "The list is initially empty." << endl;
    }

    cout << "C++ learning courses:" << endl;
    // Insert level and description pairs
    intList.insertNode({1, "Learn C++ Basics"});
    intList.insertNode({2, "Learn Functions"});
    intList.insertNode({3, "Learn C++ Classes"});
    intList.insertNode({4, "Learn OOP"});
    intList.insertNode({5, "Data Structures"});

    // Check again if the list is empty
    if (!intList.isEmpty()) {
        cout << "The list is no longer empty after adding elements." << endl;
    }

    // Display the linked list
    intList.display();

    return 0;
}
