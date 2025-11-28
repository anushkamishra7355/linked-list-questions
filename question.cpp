//search for an element in SLL
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node(int data){
        this->data=data;
        this->next=NULL;

    }
    };
    bool searchelement(node* &head,int key){
    node *temp= head;
    while(temp!=NULL){
         if(temp->data== key){
        return true;
        
    }
    temp = temp->next;

    }
    return false;
};

int main(){
    node* node1 = new node(10);
    node* node2 = new node(20);
    node* node3 = new node(30);
    node* node4 = new node(40);
    node* node5 = new node(50);
     node* head=node1;
     

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
   
    if(searchelement(head,20)){
        cout<<"found"<<endl;
    }else{
        cout<<"not found";
    }
    
    return 0;



}
