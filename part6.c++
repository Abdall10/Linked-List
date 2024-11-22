#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head= NULL;
void insertNode(int value);
void display();
void deleteNode(int value);

int main() {
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(20);
    cout << "Linked List: \n";
    display();
    deleteNode(10);
    cout << "Linked List after deletion: \n";
    display();
    
    return 0;
}

void insertNode(int value){
    node* newNode, *lastNode;
    newNode = new node;
    newNode->data = value;

    if(head == NULL){
        head = newNode;
        newNode->next=NULL;
    }else{
      lastNode = head; 
      while(lastNode->next != NULL){
        lastNode= lastNode->next;
      }
      lastNode->next = newNode;
      newNode = NULL;
    }
}

void display(){
    node* current_node;
    if(head == NULL){
        cout<<"linked List is empty"<<endl;
    }else{
        current_node = head;
        while(current_node !=NULL){
            cout<<current_node->data<<"\n";
            current_node=current_node->next;
        }
    }

}

// deleteNode function is not implemented 
void deleteNode(int value){
    node* current, *previous;
    current = head;
     previous= head;

     if(current->data == value) {
        head= current->next;
        free(current);  // free delete the node in memory
        return;
     }
     while (current->data != value) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}