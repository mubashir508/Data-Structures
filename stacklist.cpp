#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
};
class stack{
  public:
    node*top;
    int n=0;
    stack(){
        top=nullptr;
    }   
};
class singly{
  public:
    node*head;
    node*loc;
    node*ploc;
    int n=0;
    singly(){
        head=nullptr;
        loc=nullptr;
        ploc=nullptr;
    }
    bool isEmpty(){
        if(head==nullptr){
            return true;
        }
        else{
        return false;
        }
    }
    int size(){
        node*temp=head;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        cout<<"Length of Linked List is: "<<n<<endl;
        return n;
    }
    void insertAtEnd(int a){
        node*n1=new node();
        n1->data=a;
        n1->next=nullptr;
        if(head==nullptr){
            head=n1;
        }
        else{
            node*temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
        temp->next=n1;
        }
    }
    void printList(){
        node*temp=head;
        if(head==nullptr){
            cout<<"List is empty"<<endl;
        }
        while(temp!=nullptr){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }

};
int main(){
singly s1;
s1.insertAtEnd(10);
s1.insertAtEnd(20);
s1.insertAtEnd(30);
s1.insertAtEnd(40);
s1.printList();
}