#include <iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
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
    void insertAtFront(int a){
        node* n1=new node();
        n1->data=a;
        n1->next=head;
        head=n1;
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
    void insertSorted(int a){
        node *n1=new node();
        n1->data=a;
        node*temp=head;
        if(temp==nullptr){
            insertAtFront(a);
        }
        if(a<temp->data){
                    insertAtFront(a);
                }
        else{
            while(temp->next!=nullptr){
                if(a<temp->next->data){
                    n1->next=temp->next;
                    temp->next=n1;
                    return;
                }
                temp=temp->next;
            }
             insertAtEnd(a);
        }
    }
    void searchNode(int a){
        node*temp=head;
        int i=0;
        if (temp==nullptr){
            cout<<"Couldn't search because list is empty"<<endl;
        }
        else{
            while(temp!=nullptr){
                if(temp->data==a){
                    cout<<"Node Found at "<<i<<"th position"<<endl;
                    break;
                }
                temp=temp->next;
                i++;
            }
            if(temp==nullptr){
                    cout<<"Value not found"<<endl;
                }
        }
    }
    void delNode(int a) {
    if (head == nullptr) {
        cout << "Node does not exist" << endl;
        return;
    }

    if (head->data == a) {
        node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted" << endl;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == a) {
            node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Node deleted" << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Value not found" << endl;
}
    void destroyList(){
        node*temp=head;
        if(temp==nullptr){
            cout<<"List is already empty"<<endl;
        }
        else{
            while(temp->next!=nullptr){
                node*current=temp;
                temp=temp->next;
                delete current;
            }
            delete temp;
            cout<<"List detroyed Successfully"<<endl;
            head=nullptr;
        }
    }
    void searchpos(int pos)
    {
    	if(!isEmpty())
    	{
			if(n > pos && pos > 0)
    		{
    			loc = head;
    			ploc = NULL; 
				for(int i = 0; i < pos-1; i++)
    			{		
    				ploc = loc;
					loc = loc->next;
				}
				cout << "The value at position " << pos << " is " << loc->data << endl;	
			}
			else
			{
				cout << "Invalid position" << endl;
			}
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}
    void reverseLinkedList() {
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    node* current = head;
    node* nextNode = current->next;

    if (nextNode != nullptr) {
        head = nextNode; 
        reverseLinkedList(); 
        nextNode->next = current;
        current->next = nullptr;
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
    void printListReverse() {
    if (head == nullptr) {
        return;
    }
    node* temp = head; 
    head = head->next; 
    printListReverse();

    cout << temp->data << "  ";
}

};

int main(){
    singly s1;

    s1.insertAtFront(6);
    s1.insertAtFront(4);
    s1.insertAtEnd(10);
    s1.insertAtEnd(12);
    s1.searchNode(12);
    s1.size();
    // s1.printList();
    // s1.delNode(8);
    // s1.printList();
    // s1.destroyList();
    // s1.printList();
    s1.insertSorted(5);
    // cout<<"Appending"<<endl;
    s1.printList();
    s1.searchpos(3);

}