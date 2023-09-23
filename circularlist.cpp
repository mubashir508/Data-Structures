#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class circular
{
public:
    node *current;
    circular()
    {
        current = nullptr;
    }

    bool isEmpty()
    {
        return current == nullptr;
    }
    void insertAtFront(int a)
    {
        node *n1 = new node();
        n1->data = a;
        if (isEmpty())
        {
            current = n1;
            n1->next = current;
        }
        else
        {
            node *temp = current;
            while (temp->next != current)
            {
                temp = temp->next;
            }

            temp->next = n1;
            n1->next = current;
            current = n1;
        }
    }
    void insertAtTail(int a)
    {
        node *n1 = new node();
        n1->data = a;
        if (current == nullptr)
        {
            current = n1;
            n1->next = current;
        }
        else
        {
            node *temp = current;
            while (temp->next != current)
            {
                temp = temp->next;
            }
            temp->next = n1;
            n1->next = current;
        }
    }
    void insertSorted(int a){
        node*n1=new node();
        n1->data=a;
        node*temp=current;
        if(isEmpty()){
            insertAtFront(a);
        }
        if(a<temp->data){
            insertAtFront(a);
        }
        else{
            
            while(temp->next!=current){
                if(a<temp->next->data){
                    n1->next=temp->next;
                    temp->next=n1;
                    return;
                }
                temp=temp->next;
            }
            temp->next=n1;
            n1->next=current;
        }
    }
    void search(int a){
        node*temp=current;
        int n=0;
        if(isEmpty()){
            cout<<"List is Empty. Can't find"<<endl;
        }
        else{
            while(temp->next!=current){
                if(a==temp->data){
                    cout<<"Element Found at "<<n<<"th index"<<endl;
                    return;
                }
                temp=temp->next;
                n++;
            }
            cout<<"Element not found"<<endl;
        }
    }
    void delNode(int a){
        node*temp=current;
        if(isEmpty()){
            cout<<"Can't delete value because list is already empty"<<endl;
        }
        else{
            while(temp->next!=current){  
                if(a==temp->next->data){
                    node*temp2=temp->next;
                    temp->next=temp->next->next;
                    temp2->next=nullptr;
                    delete temp2;
                    cout<<"Element Deleted"<<endl;
                    return;
                }
                temp=temp->next;
            }
            cout<<"Value does not exist so it can't be deleted"<<endl;
        }
    }
    void destroyList(){
        if(isEmpty()){
            cout<<"List is already empty"<<endl;
        }
        node*temp=current;
        while(temp->next!=current){
            node*temp2=temp;
            temp=temp->next;
            delete temp2;
        }
        delete temp;
        current=nullptr;
    }
    void printList()
    {
        node *temp = current;
        if (temp == nullptr)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while (temp->next != current)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data << endl;
            ;
        }
    }
};

int main()
{
    circular c1;
    c1.insertAtTail(15);
    c1.insertAtTail(18);
    c1.insertAtTail(21);
    c1.insertAtTail(23);
    c1.insertAtFront(12);
    c1.insertAtFront(8);
    c1.insertAtFront(5);
    c1.printList();
    cout<<"appending"<<endl;
    c1.insertSorted(2);
    c1.printList();
    c1.search(1);
    c1.delNode(5);
    c1.printList();
    c1.destroyList();
    c1.printList();

    return 0;
}