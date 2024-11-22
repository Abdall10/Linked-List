#include <iostream> 
using namespace std; 

template <typename T> // Template declaration to make the class work with any data type.
struct Node {
    T data; // Stores the data of the node (generic type T).
    Node<T>* next; // Pointer to the next node in the linked list.

    Node(const T& data) : data(data), next(nullptr) {} // Constructor to initialize node data and set `next` to nullptr.
};

template <typename T> // Template declaration for the linked list class.
class LinkedList {
private:
    Node<T>* head; // Pointer to the first node in the list.

public:
    LinkedList() : head(nullptr) {} // Constructor initializes the linked list with an empty head.

    ~LinkedList() { // Destructor to clean up dynamically allocated memory.
        while (head) { // Loop through the list.
            Node<T>* temp = head; // Temporarily store the current head node.
            head = head->next; // Move to the next node.
            delete temp; // Delete the current node.
        }
    }

    void insertAtBeginning(const T& data) { // Method to insert a node at the beginning.
        Node<T>* newNode = new Node<T>(data); // Create a new node with the given data.
        newNode->next = head; // Point the new node's `next` to the current head.
        head = newNode; // Update the head to the new node.
    }

    void insertAtEnd(const T& data) { // Method to insert a node at the end.
        Node<T>* newNode = new Node<T>(data); // Create a new node with the given data.
        if (!head) { // If the list is empty:
            head = newNode; // Set the new node as the head.
            return; // Exit the method.
        }
        Node<T>* temp = head; // Temporary pointer to traverse the list.
        while (temp->next) { // Traverse until the last node.
            temp = temp->next; // Move to the next node.
        }
        temp->next = newNode; // Point the last node's `next` to the new node.
    }

    void deleteNode(const T& data) { // Method to delete a node with the specified data.
        if (!head) { // If the list is empty:
            return; // Exit the method.
        }

        if (head->data == data) { // If the head node contains the data:
            Node<T>* temp = head; // Temporarily store the head node.
            head = head->next; // Update the head to the next node.
            delete temp; // Delete the old head node.
            return; // Exit the method.
        }

        Node<T>* current = head; // Pointer to traverse the list.
        Node<T>* previous = nullptr; // Pointer to track the previous node.
        while (current && current->data != data) { // Traverse until the data is found or end of list.
            previous = current; // Update previous to current.
            current = current->next; // Move to the next node.
        }

        if (current) { // If the data was found:
            previous->next = current->next; // Bypass the current node.
            delete current; // Delete the current node.
        }
    }

    void printList() { // Method to print all elements in the list.
        Node<T>* temp = head; // Pointer to traverse the list.
        while (temp) { // Loop until the end of the list.
            cout << temp->data << " "; // Print the data of the current node.
            temp = temp->next; // Move to the next node.
        }
        cout << endl; // Print a newline at the end.
    }

    bool isEmpty() { // Method to check if the list is empty.
        return head == nullptr; // Returns true if `head` is nullptr, otherwise false.
    }

    int length() { // Method to calculate the number of nodes in the list.
        int count = 0; // Initialize counter.
        Node<T>* temp = head; // Pointer to traverse the list.
        while (temp) { // Loop through each node.
            count++; // Increment the counter.
            temp = temp->next; // Move to the next node.
        }
        return count; // Return the total count.
    }
};

int main() {
    LinkedList<int> intList; // Create a linked list of integers.
    intList.insertAtBeginning(5); // Insert 5 at the beginning. List: 5
    intList.insertAtEnd(10); // Insert 10 at the end. List: 5 -> 10
    intList.insertAtBeginning(2); // Insert 2 at the beginning. List: 2 -> 5 -> 10
    intList.printList(); // Output: 2 5 10
    intList.deleteNode(5); // Delete the node with data 5. List: 2 -> 10
    intList.printList(); // Output: 2 10
    cout << "Length: " << intList.length() << endl; // Output the length of the list: Length: 2
    cout << "Is Empty: " << intList.isEmpty() << endl; // Check if the list is empty: Is Empty: false

    LinkedList<string> stringList; // Create a linked list of strings.
    stringList.insertAtEnd("hello"); // Insert "hello" at the end. List: hello
    stringList.insertAtBeginning("world"); // Insert "world" at the beginning. List: world -> hello
    stringList.printList(); // Output: world hello
    stringList.deleteNode("world"); // Delete the node with data "world". List: hello
    stringList.printList(); // Output: hello

    return 0; // Return 0 to indicate successful execution.
}
