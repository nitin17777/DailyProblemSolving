#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node *right;

    Node(int d)
    {
        this->right = NULL;
        this->left = NULL;
        this->data = d;
    }
};

void inorder(Node* root,vector<int>&in)
{
    if(root == NULL)
    return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* inorderToBST(int s,int e, vector<int>&in)
{
    //base case
    if(s>e)
    return NULL;

    int mid = (s+e)/2;
    
    Node* root = new Node(in[mid]);


    root ->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);

    return root;
}

Node* balanced(Node* root)
{
    vector<int>inorderVal;

    //storing the inorder
    inorder(root,inorderVal);

    return inorderToBST(0,inorderVal.size()- 1,inorderVal);
}

void printAns(Node*root)
{
    if(root == NULL)
    return;

    printAns(root->left);
    cout<<root->data<<" ";
    printAns(root->right);

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


    Node* ans = balanced(root);

    cout<<"Balanced BST: ";
    printAns(ans);


    return 0;
}