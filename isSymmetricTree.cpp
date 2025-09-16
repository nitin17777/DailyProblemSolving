#include<iostream>
#include<vector>
using namespace std;


struct Node
{
    int data;
    Node* right;
    Node * left;

    Node(int data)
    {
        this->data = data;
        this ->right = NULL;
        this ->left = NULL;
    }
};


bool isMirror(Node * t1, Node * t2)
{

    if(t1 == NULL && t2 == NULL) return true;

    if(t1 == NULL || t2 == NULL) return false;


    return ( t1 ->data == t2->data) && isMirror(t1->left, t2 ->right) && isMirror(t1->right ,t2->left);
}

bool isSymmetric(Node* root) {
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}

   

int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root ->left ->left = new Node(5);
    root ->left ->right = new Node(4);

    root->right = new Node(2);
    root ->right ->right = new Node(3);
    root ->right ->left = new Node(4);
    
    if(isSymmetric(root))
    cout<<"Symmetric" <<endl;

    else
    cout<<"Not Symmetric"<<endl;

    return 0;
}