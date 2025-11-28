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

// insertion at head
void insertionAthead(node* &head,int d){ //& is used to be in originality mtlan orginal me kaam ho
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
    int count = 1;
    while(count<position - 1){
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
// printing of the nodes
void printing(node* &head){
    node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next; //forwarding the temp


    }
    cout<<endl;

}

int main(){
    // created a new node
    node* node1 = new node(10);
    //pointed the head to node1
    node* head=node1;
    
   /* printing(head); // before inserting at the head
    insertionAthead(head,12);
    printing(head); // after insertion at head
    insertionAthead(head,15);
    printing(head);
*/
    node* tail=node1;
    printing(head);
    insertionAttail(tail,20);
    printing(head);
    insertionAttail(tail,30);
    printing(head);
    insertionAtposition(tail,head,5,15);
    printing(head);
    

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;


    return 0;

}