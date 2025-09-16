#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;

    }
};

// if the left child is NULL,print the current node and move to right

//if the left child is not NULL find the inorder predeccesor(rightmost node in the left)

//if predecessor's right is NULL, make a temporary thread to current node and move left

//if predecessor's right is the current node , remove the thread, oorint the node and move right

void morrisInorder(Node* root)
{

    Node* curr = root;
    while(curr != NULL)
    {
    if(curr->left == NULL)
    {
        cout<< curr->data <<" ";
        curr = curr->right;
    }
    else
    {
        Node* pred = curr->left;
        while(pred -> right != NULL && pred ->right != curr)
        {
            pred = pred ->right;
        }
    

    if(pred ->right == NULL)
    {
        pred ->right = curr;
        curr = curr->left;

    }

    else
    {
        pred -> right = NULL;
        cout<< curr->data <<" ";
        curr = curr ->right;

    }
}
}
}

int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout<<"Morris Inorder Traversal: ";
    morrisInorder(root);


}