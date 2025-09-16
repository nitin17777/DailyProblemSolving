#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Node
{
    Node* right;
    Node* left;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
    
};

bool hasPathSum(Node* root,int targetSum)
{
    //we have to check if there is any path from root to leaf such path sum = required Sum

    if(root == NULL)
    return false;


    // when a leaf node is found
    if(root->left == NULL && root->right == NULL)
    {
        return(targetSum == root->data);
    }

    return hasPathSum(root->left,targetSum - root->data) || 
           hasPathSum(root->right,targetSum - root->data);
}


int main()
{
    Node* root = new Node(5);
    root->left= new Node(4);
    root->left->left= new Node(11);
    root->left->left->left= new Node(7);
    root->left->left->right= new Node(2);
    root->right= new Node(8);
    root->right->left= new Node(13);
    root->right->right= new Node(4);
    root->right->right->right= new Node(1);

    int targetSum = 22;

    if(hasPathSum(root,targetSum))
    cout<<"True"<<endl;

    else
    cout<<"False"<<endl;
    return 0;
}

