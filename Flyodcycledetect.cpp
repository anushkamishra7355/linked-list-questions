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
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow= slow->next;
    
    if(slow==fast)
        cout<<"cycle is found "<<slow->data<<endl;
        return slow;

    
    }
    return NULL;
    


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
// Creating nodes
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    third->next=second;
    

    
    // fourth->next = second;   // cycle starts at node with data = 2

    // Detect cycle
    if (floydcycledetect(head)) {
        cout << "Cycle is present in the linked list" << endl;
    } else {
        cout << "No cycle present" << endl;
        
        
    }

    return 0;
}
// S.C. is now O(1)
//T.C. is now O(n)
