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
        this-> left = NULL;
        this ->data = d;
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


Node* flatten(Node* root)
{
    vector<int>inorderVal;

    //storing the sorted value(inorder)
    inorder(root,inorderVal);

    int n = inorderVal.size();

    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;

    //2nd step
    for(int i = 1; i<n; i++)
    {
        Node* temp = new Node(inorderVal[i]);

        curr->left = NULL;
        curr ->right = temp ;
        curr = temp;
    }

    //3rd step: poitning left and right of last one to NULL
    curr-> left = NULL;
    curr-> right = NULL;

    return newRoot;

}

Node * printAns(Node* root)
{
    Node* curr = root;
    while(curr != NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->right;
    }
    cout<<endl;

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

    Node* ans = flatten(root);


    cout<<"Flattened BST: ";
    printAns(ans);

    return 0;

}