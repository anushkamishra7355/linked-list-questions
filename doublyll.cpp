#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *prev;
    node *next;
    //construcor
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }

};
//traversing a linked list
void printing(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
         temp=temp->next;
    }
    cout<<endl;
}
//length of the linked list 
int getLength(node* head){
    int len=0;
    node* temp=head;
    while(temp!=NULL){
        len++;
         temp=temp->next;
    }
    return len;

}
void insertAthead(node* &head,int data){
    //EMPTY LIST 
    if(head==NULL){
        node* temp= new node(data);
        head=temp;

    }else{
        node *temp = new node(data);
    node * prev = new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
    
}
void insertAttail(node* tail,int data){
    if(tail==NULL){
        node* temp= new node(data);
        tail=temp;

    }else{
        node *temp = new node(data);
    node *prev = new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
   

    }
    
   
}
void insertionAtposition(node* &tail,node* &head,int position,int d){
    if(position == 1){ //so that pehle element me insert hojaye means insert at the start
        insertAthead(head,d);
        return;

    }
    node* temp=head;
    int count = 1;
    while(count<position - 1){ //middle 
        temp = temp->next;
        count++;
    }
    //inserting at the last position
    if(temp->next==NULL){
        insertAttail(tail,d);
        return;
    }
    node* nodetoinsert= new node(d);
    node* prev = new node(d);
    nodetoinsert->next=temp->next;
    temp ->next->prev=nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev=temp;
    
    


}
int main(){
    node* node1=new node(10);
    
    node* head= NULL;
    node* tail= NULL;
    printing(head);
    cout<< getLength(head)<<endl;
    insertAthead(head,9);
    printing(head);

    insertAttail(tail,8);
    printing(head);
    insertionAtposition(tail,head,3,100);
    printing(head);


    return 0;
}