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
    node* reverseKGroup(node* head, int k) {
        if(head==NULL ){
        return head;
    }
        node* prev=NULL;
        node* curr=head;
        int count=0;
        node* forward=NULL;
        while(curr!=NULL && count<k){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
}
        //recursion
         if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
            

         }
         return prev;
    }
    void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    int k=2;
    head= reverseKGroup(head,k);  
   
    printList(head);

    return 0;

    
}