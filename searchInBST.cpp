#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this ->data = d;

        this ->left = NULL;
        this ->right = NULL;

        
    }
};

bool searchBST(Node* root,int x )
{
    if(root == NULL)
    {
        return false;
    }

    if(root->data == x)
    {
        return true;

    }

    else if(root->data > x )
    return searchBST(root->left,x);

    else
    {
        return searchBST(root->right,x);

    }

}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    int x = 5;

    if(searchBST(root,x))
    {
        cout<<x<<" is found."<<endl;

    }
    else
    {
        cout<<x<<" is not found."<<endl;
    }
 
    return 0;

}