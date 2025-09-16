#include<bits/stdc++.h>
using namespace std;

//height of binary tree is basically the longest path between root node and the leaf node

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this ->left = NULL;
        this ->right = NULL;
    }
};

int height(struct Node* node)
{
    //base case
    if(node == NULL)
    {
        return 0;

    }

    int left = height(node ->left);
    int right = height(node ->right);

    int ans = max(left,right) +1;
    return ans;

}

int main()
{ 
    Node * root = new Node(1);
    root ->left = new Node(2);
    root ->right = new Node(3);

    root-> left -> left = new Node(4);
    root ->left ->right = new Node(5);


    cout<<"Height of binary tree: "<< height(root)<<endl;

    return 0;

}