#include<iostream>
using namespace std;
//creation of datatype 
class node{
    public:
    int data;
    node*next;


//constructor
node(int data){
    this->data=data;
    this->next=NULL;
}
};
node* middle(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*first=head->next;
    node*second = head;
    while(first!=NULL){
        first=first->next;
        if(first!=NULL){
            first=first->next;
        }
        second = second->next;

    }
    return second;
}
int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);

    node* mid = middle(head);   

    cout << "Middle: " << mid->data << endl;

    
}
