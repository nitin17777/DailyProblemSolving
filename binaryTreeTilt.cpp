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


//tilt is the absolute difference between sum of all left subtree node values and all right subtree values

//if no subtree is found on either side , sum is considered to be zero



int calcTilt(Node * root,int& totalTilt)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftSum = calcTilt(root->left, totalTilt);
    int rightSum = calcTilt(root->right, totalTilt);

    int nodeTilt = abs(leftSum - rightSum);
    
    totalTilt += nodeTilt;

    return leftSum + rightSum + root->data;
}

int findTilt(Node* root)
{
    int totalTilt = 0;
    calcTilt(root, totalTilt);
    return totalTilt;
}

int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right= new Node(3);

    int anss = findTilt(root);

    cout<< anss <<endl;

    return 0;

}

