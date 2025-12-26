#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory free  "<<val<<endl;


    }

};
void insertnode(node* &tail, int element, int d){
    //assumimg that the element is present in linked list

    //1. empty list
    if(tail==NULL){
         node* temp= new node(d);
         tail=temp;
         temp->next=temp;
    }//non empty list else wala part
    else{
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next; 
        }
        //element found -> curr is representing lement wala node 
        node* temp=new node(d);
        temp->next=curr->next;
        curr->next=temp;


    }

    
}

void deletenode(node* &tail, int val){
    if(tail==NULL){
        cout<<"LIST IS EMPTY PL CHECK AGAIN"<<endl;
        return;
    }

    else{
        //non-empty
        //assumimg that the value "val" is  presentr in the linked list 
        node *prev = tail;
        node* curr=prev->next;

        while(curr->data != val){
            prev=curr;
            curr=curr->next;

        }
        prev ->next =curr->next;

        //1 node  linked list
        if(curr== prev){
            tail=NULL;
        }
        //>=2 NODE LINKED LIST
        else if(tail==curr){
            tail=prev;

        }




        if(tail==curr){
            tail=prev;

        }
        curr->next=NULL;
        delete curr;




    }


}
void print(node* tail){

    node * temp = tail;

    //
    if(tail==NULL){
        cout<<"list is empty"<<endl;
    }
    do{
    cout<<tail->data<<" ";
    tail=tail->next;
    }
    while(tail != temp);
    cout<<endl;
   
}


int main(){
node* tail=NULL;
insertnode(tail,5,3);
print(tail); //empty list code 

/*insertnode(tail,3,4);
print(tail);

insertnode(tail,4,5);
print(tail);

insertnode(tail,4,2);
print(tail);
*/
deletenode(tail,3);
print(tail);

return 0;
}
//circular linked list done!