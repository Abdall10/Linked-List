#include <iostream>
using namespace std;

// Delete END

struct node {
    int data;
    node* next;
};

node* head= NULL;
void insertNode(int value);
void display();
void delete_end(int value);

int main() {
    cout << "The Linked List old: \n";
    insertNode(10);
    insertNode(20);
    insertNode(30);
    display();
    cout << "Linked list after the elements to be deleted from the end direction: \n";
    delete_end(1);
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


// The function deletes the end  element  in the linked list

void delete_end(int value){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }else if(head->next == NULL){ // With this condition, there is only one element in node
       delete(head);   // delete the head node
       head = NULL;
    }else{  // In this case there is more than one element in node
        node* last_node = head ;
        while(last_node->next->next != NULL){ 
          last_node = last_node->next ;
        }
        delete(last_node->next);
        last_node->next = NULL ; 
    }
}