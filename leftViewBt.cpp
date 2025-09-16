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

void solve(Node* root,vector<int>&ans,int level)
{
    if(root == NULL)
    return;

    if(level == ans.size())
    {
        ans.push_back(root->data);

        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }

}

vector<int>leftView(Node* root)
{
vector<int>ans;
solve(root,ans,0);
return ans;
}

int main()
{
    return 0;

}
