#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node * left;

    Node(int d)
    {
        this ->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};



bool isBST(Node*root, int min , int max)
{

    //base case
    if(root == NULL)
        return true;

    if(root ->data >= min && root ->data <= max)
    {
        bool left = isBST(root ->left , min, root->data);
        bool right = isBST(root->right , root->data, max);
        return left && right;

    }
    else
    return false;

}
bool validateBST(Node* root)
{
    return(isBST(root, INT_MIN,INT_MAX));

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

    if(validateBST)
    {
        cout<<"Validated BST"<<endl;

    }

    else
    {
        cout<<"BST is not validated."<<endl;

    }

    return 0;
    

}