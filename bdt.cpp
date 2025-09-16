#include<bits/stdc++.h>
using namespace std;


void traverseLeft(Node * root,vector<int>&ans)
{
    if(root == NULL || (root->left == NULL && root->right))
    {
        return;
    }

    ans.push_back(root);
    if(root->left)
    {
        traverseLeft(root->left,ans);

    }
    else
    {
        traverseLeft(root->right,ans);
    }

    void traverseRight(Node* root,vector<int>ans)
    {
        if(root == NULL || (root->left == NULL && root ->right == NULL))
        {
            return root;

        }

        if(root ->right)
        {
            traverseRight(root->right,ans);


        }
        else
        {
            traverseLeft(root -> left ,ans);

        }

        ans.push_back(root->data);
    }  
}

vector<int>traverseLeaf(Node* root,vector<int>& ans)
{
    //base case
    if(root == NULL)
    {
        return ;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

vector<int>boundary(Node* root)
{

    vector<int>ans;

    if(root == NULL)
    {
        return ans;
    }

    //left part
    traverseLeft(root->left,ans);
    
    //left subtree
    traverseLeaf(root->left,ans);

    //right subtree
    traverseLeaf(root->right,ans);


    //right tree
    traverseRight(root->right,ans);
}


//LeftViw

void solve(Node* root,vector<int>&ans,int level)
{
    if(root == NULL)
    {
        return ;
    }

    if(level == ans.size())
    {
        ans.push_back(root->data);

    }

    solve(root->left,ans,level+1);
    
    solve(root->right,ans,level+1);
}

vector<int> leftView(Node* root)
{
    vector<int>ans;
    solve(root,ans,0);
    return ans;

}






vector<int>verticalOrder(Node* root)
{
    map<int , map<int,vector<int>>>nodes;
    queue
}