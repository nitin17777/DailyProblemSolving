#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* invertTree(Node * root)
{
    //we just simply have to reverse the every conterpart of the given binary tree

    //base case for recursion
    if(root == NULL)
    {
        return NULL;

    }

    Node * temp = root ->left;
    root->left = root->right;
    root ->right = temp;

    //recursion now

    invertTree(root->left);
    invertTree(root ->right);

    return root;
  
}

void inOrder(Node* root)
{
    if(root == NULL)
    return;

    inOrder(root ->left);

    cout<<root->data<<" ";

    inOrder(root ->right);
}

int main()
{
    Node* root = new Node(4);
    root ->left = new Node(2);
    root ->left ->left = new Node(1);
    root->left ->right = new Node(3);

    root->right = new Node(7);
    root ->right->left = new Node(6);
    root ->right ->right = new Node(9);

    cout<<"Original Tree: ";
    inOrder(root);
    cout<<endl;

    root = invertTree(root);
    cout<<"Inverted Tree: ";
    inOrder(root);
    cout << endl;
    
    return 0;

}