#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right =NULL;
    }
};

pair<int,int>preSucc(Node* root,int key)
{

    int pred = -1,succ =-1;


    //find key
    Node*temp = root;

    while(temp->data != key)
    {
        if(temp ->data > key)
        {
            succ = temp->data;
            temp = temp->left;
            

        }
        else
        {
            pred = temp ->data;

            temp = temp->right;

        }
    }


    // pred and succ

    //pred
    Node * leftTree = temp->left;
    while(leftTree != NULL)
    {
        pred = leftTree ->data;
        leftTree = leftTree->right;
    }


    //succ

    Node* rightTree = temp->right;
    while(rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;

    }


    pair<int,int>ans = make_pair(pred,succ);

    return ans;

    //or: return {pred,succ}

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





    return 0;

}
