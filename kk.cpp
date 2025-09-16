#include<bits/stdc++.h>
using namespace std;

struct Node()
{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};


//creating a mapping between elements and their respective indices
void createMapping(int in[],map<int,int>&nodeToIndex,int n)
{
    for(int i = 0 ;i<n; i++)
    {
        nodeToIndex[in[i]] = i;

    }
}


Node* solve(int in[], int pre[],int post[], int& index, int inorderStart,int inOrderEnd,int n , map<int,int>nodeToIndex)
{
    //base case
    if(index >= n || inorderStart > inorderEnd)
    {
        return NULL;

    }

    int element = pre

}



int main()
{
    return 0;

}