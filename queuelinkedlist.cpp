#include <iostream>
using namespace std;
#define n 100

class node{
    public:
        int data;
        node*next;
};
class queue{
    public:
        node* front;
        node* rear;
        queue(){
            front=nullptr;
            rear=nullptr;
        }
    
    bool isEmpty(){
        if(front==nullptr){
            return true;
        }
    return false;
    }
    void enqueue(int a){
        node*nn =new node();
        nn->data=a;
        if (isEmpty()) {
            front = rear = nn;
        } else {
            rear->next = nn;
            rear = nn;
        }
    }
    void dequeue(){
        
        if(isEmpty()){
            cout<<"Queue is already empty"<<endl;
        }
        else{
            node* temp=front;
            front=front->next;
            delete temp;
        }
    }
    void printQueue(){
        node*temp=front;
        while (temp->next!=nullptr)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
        
    }

};

int main(){
    queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.printQueue();
    q1.dequeue();
    q1.printQueue();
    return 0;
}