#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;

    Node(int d)
    {
        this ->data = d;;
        this->right = NULL;
        this->left = NULL;

    }
};

Node * minVal(Node* root)
{

    Node * temp = root;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node * temp = root;
    while(temp && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
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

    Node * maxNode = maxVal(root);
    Node * minNode = minVal(root);

    cout<<"Max Value is: "<< (maxNode ? maxNode->data: -1) <<endl;
    
    cout<<"Min value is: "<<(minNode ? minNode->data : -1)<<endl;

    return 0;

}