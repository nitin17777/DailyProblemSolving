#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        this ->left = NULL;
        this->right = NULL;

    }
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //find the lowest node in tree that consists of both right and left

    //Return if null, p or q found
    if(root==NULL || root==p || root == q)return root;

    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left && right) return root;
    else if(left)return left;
    else return right;


//     //Return if right and left of this node doesn't return NULL -> THis is LCA
//     if(left!=NULL && right != NULL)return root;

//     //Otherwise return the non null side
//     return (left!= NULL) ? left:right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    
    }

    return 0;
}