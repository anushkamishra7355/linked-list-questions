#include<iostream>
#include<map>
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
bool detectcycle(node* head){
     if(head==NULL){
        return false;
        
    }
    node* temp=head;
    map<node*,bool> visited;
    while(temp!=NULL){
    if(visited[temp] == true){
        cout<<"this is the element "<<temp->data<<endl;
        return true;
    }
    visited[temp]=true;
    temp=temp->next;

}
return false;
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
int main() {
    // Creating nodes
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next=second;

    
    // fourth->next = second;   // cycle starts at node with data = 2

    // Detect cycle
    if (detectcycle(head)) {
        cout << "Cycle is present in the linked list" << endl;
    } else {
        cout << "No cycle present" << endl;
        cout << "Linked List: ";
        printing(head);
    }

    return 0;
}

// time complexity 
// as we are using map so that space complexity is O(n)
// and the T.C. is also O(n)
// TO GET O(1) SPACE COMPLEXITY WE ARE GOING TO USE FLOYD'S CYCLE DETECTION ALGORITHM --->>>

