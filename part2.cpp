#include <iostream> 
using namespace std; 

struct node {
     int value=0;
     node* next;  
};

node *head = NULL;
// insert function
void insertNode(int  data){
    // new pointer
    node* newNode;
    node *last;
    newNode = new node; // create a new node
    newNode->value = data; // assign value to the new node
    if(head==NULL){
        head = newNode;
        newNode->next = NULL;
    }
    else{
        last = head;
        while (last->next !=NULL)
        {
            last=last->next;
        }
        last->next= newNode;
        newNode->next=NULL;
    }
};
// Display function to  appear values of linked list
void display(){
    node* currentNode;
   // if head is null
   if(head==NULL){
    cout<<"Linked List is empty"<<endl;
   }
   else{
    currentNode = head;
    while(currentNode != NULL){
        cout<<currentNode->value<<" \n";
        currentNode = currentNode->next;
    }
   }
}

int main() {
     
     cout<<"Linked list \n";
     insertNode(10);
     insertNode(20);
     insertNode(30);
     insertNode(40);
     insertNode(50);
     display();
    return 0; 
}