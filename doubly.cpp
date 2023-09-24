#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* prev;
        node* next;
};
class doubly{
    public:
        node*first;
        node*last;
        node*loc;
        node*ploc;
        doubly(){
            loc=nullptr;
            ploc=nullptr;
            last=nullptr;
            first=nullptr;
        }
    
    bool isEmpty(){
        if (first==nullptr && last==nullptr){
            return true;
        }
        return false;
    }
    void insertAtFront(int a){
        node*n1=new node();
        n1->data=a;
        if(isEmpty()){
            n1->next=nullptr;
            n1->prev=nullptr;
            first=n1;
            last=n1;
        }
        else
        {
            n1->next=first;
             first->prev=n1;
            first=n1;
        }
        
    }
    void insertAtEnd(int a){
        if(isEmpty()){
            insertAtFront(a);
        }
        else{
            node*temp=first;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            node *n1=new node();
            n1->data=a;
            n1->next=nullptr;
            n1->prev=temp;
            temp->next=n1;
        }
    }

    void printList(){
        node*temp=first;
        if(isEmpty()){
            cout<<"List is empty"<<endl;
        }
        else{
        while(temp->next!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data<<endl;;
        }
    }

};

int main(){
    doubly d1;
    d1.insertAtFront(5);
    d1.insertAtFront(7);
    d1.insertAtFront(18);
    d1.insertAtEnd(10);
    d1.insertAtEnd(8);
    d1.insertAtEnd(7);
    d1.printList();
    return 0;
    
}

