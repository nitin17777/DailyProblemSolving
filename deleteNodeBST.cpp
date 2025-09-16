#include<iostream>
#include<vector>
#include<climits>
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


Node* deleteNode(Node* root,int key)
{
    //base case: when root is NULL
    if(root == NULL)
    return NULL;

    if(root == key)
    return root;

    while(root != NULL)
    {
        Node* curr = root;

        
    }



}