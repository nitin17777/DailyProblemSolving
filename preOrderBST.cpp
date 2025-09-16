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

Node* solve(vector<int> & preorder, int mini,int maxi,int & i)
{
    if(i >= preorder.size())
    return NULL;
    

    if(preorder[i]<mini || preorder[i] >maxi)
    return NULL;


    Node* root= new Node(preorder[i++]);

    root ->left = solve(preorder, mini, root->data,i);
    root ->right = solve(preorder,root->data,maxi,i);

    return root;
}


void in(Node* root)
{
    if(!root)
    return ;

    in(root->left);
    cout<<root ->data<<" ";
    in(root->right);
  
}

Node * preOrderToBST(vector<int>&preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;

    return solve(preorder,mini,maxi,i);
}

int main()
{
    vector<int>arr = {10, 5, 1, 7, 40, 50};

    Node*ans = preOrderToBST(arr);

    cout<<"Inorder: ";
    in(ans);
    

    return 0;

}