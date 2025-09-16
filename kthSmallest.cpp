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


int solve(Node*root,int & i,int k)
{

    //base case
    if(root == NULL)
    {
        return -1;

    }

    //L
    int left = solve(root->left,i,k);
    if(left != -1)
    {
        return left;
    }
    i++;

    //N

    if(i == k)
    return root->data;

    //R
    return solve(root->right,i,k);
}

int kthSmallest(Node* root, int k)
{
    int i = 0; 

    int ans = solve(root,i,k);
    return ans;


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

    int k = 4;
    

    int ans = kthSmallest(root,k);

    cout<<ans<<endl;



    return 0;

}