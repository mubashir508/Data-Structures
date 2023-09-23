#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = nullptr;
        right = nullptr;
    }
};
class tree
{
    node *root;

public:
    node *loc;
    node *ploc;
    tree()
    {
        root = nullptr;
        loc = nullptr;
        ploc = nullptr;
    }
    bool isEmpty()
    {
        return root == nullptr;
    }
    void search(int value)
    {
        loc = root;
        ploc = nullptr;
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        else
        {
            while (loc != nullptr && loc->data != value)
            {
                ploc = loc;
                if (value < loc->data)
                    loc = loc->left;
                else
                    loc = loc->right;
            }
        }
    }
    void insert(int a)
    {
        node *nn = new node();
        nn->data = a;

        if (isEmpty())
        {
            root = nn;
            loc = root;
        }
        else
        {
            search(a);

            if (a < ploc->data)
            {
                ploc->left = nn;
            }
            else
            {
                ploc->right = nn;
            }
        }
    }
    void minVal(node *loc)
    {
        if (loc->left == nullptr)
        {
            cout << "Minimum Value in BST is: " << loc->data << endl;
        }
        else
        {
            minVal(loc->left);
        }
    }
    void maxVal(node *loc)
    {
        if (loc->right == nullptr)
        {
            cout << "Maximum Value in BST is: " << loc->data << endl;
        }
        else
        {
            maxVal(loc->right);
        }
    }

    void preorder(node *loc)
    {
        if (loc == nullptr)
        {
            return;
        }
        cout << loc->data << "  ";
        preorder(loc->left);
        preorder(loc->right);
    }
    void inorder(node *loc)
    {
        if (loc == nullptr)
        {
            return;
        }
        inorder(loc->left);
        cout << loc->data << "  ";
        inorder(loc->right);
    }
    void postorder(node *loc)
    {
        if (loc == nullptr)
        {
            return;
        }
        postorder(loc->left);
        postorder(loc->right);
        cout << loc->data << "  ";
    }
};

int main()
{
    tree t1;

    t1.insert(5);
    t1.insert(3);
    t1.insert(9);
    t1.insert(7);
    t1.insert(1);
    t1.insert(2);

    t1.search(5);

    cout << "Preorder: ";
    t1.preorder(t1.loc);
    cout << endl;

    cout << "Inorder: ";
    t1.inorder(t1.loc);
    cout << endl;

    cout << "Postorder: ";
    t1.postorder(t1.loc);
    cout << endl;

    t1.minVal(t1.loc);
    t1.maxVal(t1.loc);

    return 0;
}