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
//deconstructor
~node(){
    int value=this->data;
    //memory free
    if(this->next!=NULL){
        //memory free start node 
        delete next;
        this->next=NULL;

    }
    cout<<"memory is free for node data "<< value <<endl;



}
};

// insertion at head
void insertionAthead(node* &head,int d){ //& is used to be in originality mtlab orginal me kaam ho
    // creation of new nodes 
    node* temp= new node(d);
    temp->next=head;
    head=temp;
}

void insertionAttail(node* &tail, int d){
    node* temp= new node(d);
    tail->next=temp;
    tail=temp;

}

void insertionAtposition(node* &tail,node* &head,int position,int d){
    if(position == 1){ //so that pehle element me insert hojaye means insert at the start
        insertionAthead(head,d);
        return;

    }
    node* temp=head;
    int count = 1; //POSITION HAI YE 1 MATLAB FIRST POSTIONB PE HAI
    while(count<position - 1){ //middle 
        temp = temp->next;
        count++;
    }
    //inserting at the last position
    if(temp->next==NULL){
        insertionAttail(tail,d);
        return;
    }
    node* nodetoinsert= new node(d);
    nodetoinsert->next=temp->next;
    temp ->next=nodetoinsert;
    


}

void deletionAtposition(node* &head,int position){
    //deletion at head or starting me 
    if(position==1){
        node* temp = head;
        head=head->next;
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
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;

    }
    
}
// printing of the nodes OR TRAVERSING THE LINKED LIST 
void printing(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next; //forwarding the temp means initiliaising 


    }
    cout<<endl;

}

int main(){
    // created a new node
    node* node1 = new node(10);
    //pointed the head to node1
    node* head=node1;
    
    // printing(head); // before inserting at the head
    // insertionAthead(head,12);
    // printing(head); // after insertion at head
    // insertionAthead(head,15);
    // printing(head);

    node* tail=node1;
    printing(head);
    insertionAttail(tail,20);
    printing(head);
    insertionAttail(tail,30);
    printing(head);
    insertionAtposition(tail,head,4,15);
    printing(head);

    deletionAtposition(head,4);
    printing(head);

    

    // cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;


    return 0;

}
//singly linked list done!