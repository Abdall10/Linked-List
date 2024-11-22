#include <iostream>
#include <string>
#include <map>
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

    // Function to choose levels and calculate total price
    void chooseLevels() {
        map<int, int> prices = {
            {1, 10}, {2, 10}, {3, 15}, {4, 15}, {5, 20} // Price for each level
        };

        int numLevels;
        cout << "Enter the number of levels you want to select (1-5): ";
        cin >> numLevels;

        if (numLevels < 1 || numLevels > 5) {
            cout << "Invalid number of levels. Please select between 1 and 5." << endl;
            return;
        }

        int totalPrice = 0;
        cout << "\nYou selected the following courses:" << endl;
        Node<T>* currentNode = head;
        int currentLevel = 1;
        string selectedCourses = "";

        while (currentNode != NULL && currentLevel <= numLevels) {
            cout << currentNode->value.first << " " << currentNode->value.second << endl;
            selectedCourses += currentNode->value.second + "\n";  // Concatenate course names
            totalPrice += prices[currentLevel]; // Add the price of the course
            currentNode = currentNode->next;
            currentLevel++;
        }

        // Apply discount if all 5 levels are chosen
        if (numLevels == 5) {
            cout << "\nYou qualify for a $10 discount for selecting all 5 levels!" << endl;
            totalPrice -= 10;  // Apply the $10 discount
        }

        cout << "\nThe total price of selected courses is: $" << totalPrice << endl;

        // Display selected courses and total price
        cout << "\nCourses you selected: " << endl;
        cout << selectedCourses << endl;
        cout << "Total price: $" << totalPrice << endl;
    }
};

int main() {
    LinkedList<pair<int, string>> intList; // Linked list for integer-level and string-description pairs
    cout << "Welcome to the C++ learning!" << endl;

    // Insert level and description pairs
    intList.insertNode({1, "Learn C++ Basics"});
    intList.insertNode({2, "Learn Functions"});
    intList.insertNode({3, "Learn C++ Classes"});
    intList.insertNode({4, "Learn OOP"});
    intList.insertNode({5, "Data Structures"});

    // Display the linked list of courses
    cout << "\nC++ learning courses:" << endl;
    intList.display();

    // Let the user choose levels and calculate the total price
    intList.chooseLevels();
    
    return 0;
}