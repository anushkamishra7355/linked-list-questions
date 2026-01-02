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
node* floydcycledetect(node* head)
{
    if(head==NULL || head->next==NULL){
        return 0;
    }
    
    node* fast = head;
    node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow= slow->next;
    
    if(slow==fast){
        cout<<"cycle is found "<<slow->data<<endl;
        return slow;
    }
    
    }
    return NULL;
    


}

node* getStartingNode(node* head){
    if(head==NULL)
    return NULL;
    node* intersection = floydcycledetect(head);
    node* slow = head;
    while(slow!=intersection){
        slow=slow->next;
        intersection= intersection->next;

    }
    return slow;
}
node* removeLoop(node* head){
    if(head==NULL){
        return NULL;
    }
    node* startOFloop= getStartingNode(head);
    node* temp=startOFloop;

    while(temp->next!=startOFloop){
        temp=temp->next;
    }
    temp->next=NULL;
    return 0;
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
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // create loop
    fourth->next = second;   // loop starts at 2

    node* start = getStartingNode(head);

    if(start != NULL){
        cout << "Loop starts at node with data: " << start->data << endl;
    }
    else{
        cout << "No loop present" << endl;
    }
    removeLoop(head);
    printing(head);

    return 0;
}
