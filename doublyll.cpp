#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *prev;
    node *next;
    //construtor
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free  "<<val<<endl;
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
void insertAthead(node* &head,node* &tail,int data){
    //EMPTY LIST 
    if(head==NULL){
        node* temp= new node(data);
        head=temp;
        tail=temp;

    }else{
        node *temp = new node(data);
    node * prev = new node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
    
}
void insertAttail(node* tail,node* &head,int data){
    if(tail==NULL){
        node* temp= new node(data);
        tail=temp;
        head = temp;

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
        insertAthead(head,tail,d);
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
        insertAttail(tail,head,d);
        return;
    }
    node* nodetoinsert= new node(d);
    node* prev = new node(d);
    nodetoinsert->next=temp->next;
    temp ->next->prev=nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev=temp;
    
    


}
void deletionAtposition(node* &head,int position){
    //deletion at head or starting me 
    if(position==1){
        node* temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;

        delete temp;
       
    }
    else{
        //deleting any middle node or last node
        node* curr=head;
        node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;


    }
    
}
int main(){
    node* node1=new node(10);
    
    node* head= NULL;
    node* tail= NULL;
    printing(head);
    cout<< getLength(head)<<endl;
    insertAthead(head,tail,9);
    printing(head);

    insertAttail(tail,head,8);
    printing(head);
    insertionAtposition(tail,head,2,100);
    printing(head);

    deletionAtposition(head,1);
    printing(head);



    return 0;
}
//doubly linked list done!