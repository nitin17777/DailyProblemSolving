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
        this ->right = NULL;
        this ->left = NULL;    
    }
};


void solve(Node* root ,int k,int & count,vector<int>path);
{
    //base case
    if(root == NULL)
    {
        return;

    }

    path.push_back(root->data);

    //left
    solve(root ->left,k,count,path);
    
    //right
    solve(root->right,k ,count,path);

    //check for kSum

    int size = path.size();


    for(int i = size-1; i>=0; i--)
    {
        sum +=path[i];
    }

    if(sum == k)
    {
        count ++;

    }
    path.pop_back();
    
}

int sumK(Node * root ,int k)
{
    vector<int>pathl;

    int count =0;

    solve(root,k,count,path);

}
