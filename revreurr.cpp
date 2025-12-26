#include<iostream>
using namespace std;
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
node*reverse(node* &head){
    if(head == NULL || head->next == NULL){

        return head;
    }
    node *secondhead=reverse(head -> next);
    head->next->next=head;
    head->next=NULL;
    return secondhead;




}
int main(){
    node* head = new node(1);
head->next = new node(2);
head->next->next = new node(3);
head->next->next->next = new node(4);

head = reverse(head);
 node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}