#include <iostream>
using namespace std;

// Delete Beginning

struct node {
    int data;
    node* next;
};

node* head= NULL;
void insertNode(int value);
void display();
void delete_beg(int value);

int main() {
    cout << "The Linked List old: \n";
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();
    cout << "The linked list after the elements to be deleted from the starting direction: \n";
    delete_beg(1);
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


// function delete Beginning 
// The function deletes the first element in the linked list
void delete_beg(int value){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }else{
       node* first_node = head;
       head = first_node->next;
       delete(first_node);
    }
}