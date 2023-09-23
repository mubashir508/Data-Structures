#include <iostream>
using namespace std;

class ArrayStack {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    int stack[MAX_SIZE];
    int top; // Index of the top element in the stack

public:
    ArrayStack() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack is full. Cannot push element." << endl;
            return;
        }
        stack[++top] = item;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return -1;
        }
        return stack[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No element to peek." << endl;
            return -1;
        }
        return stack[top];
    }
    int size() {
        return top + 1;
    }
    int binary(int n){
        ArrayStack s;
        if(n==0 ||n==1){
            return;
        }
        else{
            int a=n%2;
            s.push(a);
            binary(a);
        }
        return;
    }
};
int main() {
    ArrayStack stack;
    // stack.push(10);
    // stack.push(20);
    // stack.push(30);
    // cout << stack.pop() << endl; 
    // cout << stack.peek() << endl; 
    // cout << stack.size() << endl;
    // cout << stack.isEmpty() << endl;
    stack.push(20);
    cout<<stack.peek();
    return 0;
}