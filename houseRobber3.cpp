#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

pair<int,int>solve(TreeNode* root)
{
    if(root==NULL)return {0,0};

    auto left = solve(root->left);
    auto right = solve(root->right);

    //Case 1: Rob current house, then we can't rob either child
    int rob = root->val + left.second + right.second;

    //case 2 : not robbing current house, and for each child, choose whichever option gives more money
    int notRob = max(left.first,left.second) + max(right.first, right.second);

    return {rob,notRob};
}


int rob(TreeNode* root)
{

    //Police if two directly linked houses were broken into on the same night 
    //return the max amount of money thief cna rob without alerting the police

    auto ans = solve(root);

    //either rob or not rob the root
    return max(ans.first,ans.second);   
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    TreeNode* root = new TreeNode(2);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);

    cout<<rob(root)<<endl;
    
    return 0;
}