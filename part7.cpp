#include <iostream>
using namespace std;

// Insert Beginning

struct node {
    int data;
    node* next;
};

node* head= NULL;
void insertNode(int value);
void display();
void insert_beg(int value);

int main() {
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(20);
    cout << "Linked List: \n";
    display();
    insert_beg(1);
    cout << "Linked List after inserting 25 at the beginning: \n";
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

// function Insert Beginning 

void insert_beg(int value){
    node* newNode = new node;
    newNode -> data = value;
    newNode -> next = head;
    head = newNode;
}
