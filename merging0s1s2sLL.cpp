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
void insertionAttail(node* &tail, node* curr){
   
    tail->next=curr;
    tail=curr;

}
node* sortlist(node* head){
    node *headzero = new node(-1);
    node * tailzero = headzero;
     node *headone = new node(-1);   // -1 is for dummy node taki if conditions zyda na lage
    node * tailone = headone;
     node *headtwo = new node(-1);
    node * tailtwo = headtwo;

    node* curr = head;
    // created separated list of 0s 1s 2s 
    while(curr!=NULL){
          
        int val = curr->data;
        if(val == 0){
            insertionAttail(tailzero,curr);
        }else if(val == 1){
            insertionAttail(tailone,curr);
        }else if( val == 2){
            insertionAttail(tailtwo,curr);
        }
        curr = curr->next;
    }

    // merging for those sublists
    if(headone ->next!=NULL){
        tailzero->next = headone->next;
    } else{
        tailzero->next=headtwo->next;
    }
    tailone->next = headtwo->next;
    tailtwo->next=NULL;

  
    // Setting up the head as it is at now at dummy node in headzero
    head = headzero->next;
    delete headzero;
    delete headone;
    delete headtwo;

    return head;
}

void printing(node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
    



int main(){
    node* head = new node(1);
    node* tail = head;

    insertionAttail(tail, new node(0));
    insertionAttail(tail, new node(2));
    insertionAttail(tail, new node(1));
    insertionAttail(tail, new node(0));
    insertionAttail(tail, new node(2));

    cout << "Before sorting: ";
    printing(head);

    head = sortlist(head);

    cout << "After sorting: ";
    printing(head);

    return 0;
}
