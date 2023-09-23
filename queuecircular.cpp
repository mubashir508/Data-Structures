#include<iostream>
using namespace std;

class queue{
    int front;
    int rear;
    int size;
    int *arr;
    public:
    queue(){
        size=6;
        front=0;
        rear=0;
        arr=new int[size];
    }
    bool isEmpty(){
        return front==rear;
    }
    bool isFull(){
        return (rear+1)%size==front;
    }
    void enqueue(int n){
        if(isFull()){
            cout<<"Queue is already full"<<endl;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=n;
        }
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is already empty"<<endl;
        }
        else{
            front=(front+1)%size;
        }
    }
    void printQueue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else{
            int i=(front+1)%size;
            while(i!=((rear+1)%size)){
                cout<<arr[i]<<"  ";
                i=(i+1)%size;
            }
        }
    }
};

int main(){
    queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.printQueue();
    return 0;
}