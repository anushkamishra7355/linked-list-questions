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
node* sortlist(node* head){
    int zerocount=0;
    int onecount = 0;
    int twocount = 0;

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            zerocount++;
        }else if (temp->data==1){
            onecount++;
        }else if (temp->data==2){
            twocount++;
        }
        temp=temp->next;
    }
   

temp = head;
while(temp!=NULL){
   if(zerocount !=0){
    temp->data=0;
            zerocount--;
        }else if (onecount!=0){
            temp->data=1;
            onecount--;
        }else if (twocount!=0){
            temp->data=2;
            twocount--;
        }
        temp=temp->next;
    }
    return head;
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
    // Creating linked list: 1 -> 0 -> 2 -> 1 -> 0
    node* head = new node(1);
    head->next = new node(0);
    head->next->next = new node(2);
    head->next->next->next = new node(1);
    head->next->next->next->next = new node(0);

    cout << "Before sorting: ";
    printing(head);

    head = sortlist(head);

    cout << "After sorting: ";
    printing(head);

    return 0;
}
// do-do while loop hai to O(n) and  O(n) soo--->> O(2n)---> O(n)
// SC-->>o(1)