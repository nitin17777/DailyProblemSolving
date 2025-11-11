#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void flattenBST(Node* root,Node* &prev)
{
    if(root == NULL)return;

    flattenBST(root->right,prev);//processign right subtree first
    flattenBST(root->left,prev);//processign right subtree first
    

    root->right = prev;//remove the left link
    root->left = NULL;// linking previous node to current 
    prev = root; //and move prev pointer
}

void flatten(Node*& root)
{
    Node* prev = NULL;
    flattenBST(root,prev);
}

void printList(Node* root) {
    while (root) {
        cout << root->data << " ";
        root = root->right;
    }
}


int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(8);

    flatten(root);

   printList(root);

    return 0;
}