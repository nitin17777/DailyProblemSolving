#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;


    TreeNode(int data)
    {
        this->val = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int moves = 0;

int dfs(TreeNode* root)
{
    if(!root)return 0;
    
    int left = dfs(root->left),right = dfs(root->right);

    //Coins moved across edges
    moves+= abs(left) + abs(right);


    //Return excess coins to parent
    return root->val + left + right - 1;
}


int distributeCoins(TreeNode* root)
{

    /*

    In one move we may choose two ajd nodes and move one coin from one node to another

    Return the number of moves to make every node have exactly one coin

    //If number is at leaf node -


    */

    dfs(root);
    return moves;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(3);
    root->right = new TreeNode(0);
    root->left = new TreeNode(0);

    cout<<distributeCoins(root)<<endl;

    return 0;
}