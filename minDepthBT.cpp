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

/*          RECURSIVE DFS APPROACH

int minDepth(TreeNode* root)
{
    //Min depth : Number of nodes along the shortest path from root node down to the nearest leaf

    //int mini = 0;

    if(!root)return 0;

    //When onlyu one node is there
    if(!root->left && !root->right)return 1;
    if(!root->right)return 1 + minDepth(root->left);
    if(!root->left)return 1 + minDepth(root->right);


    int left = minDepth(root->left), right = minDepth(root->right);
    return 1+min(left,right);
}
*/

//         BFS APPROACH NOW

int minDepth(TreeNode* root)
{
    if(!root)return 0;
    queue<TreeNode*>q;
    q.push(root);

    int depth = 1;

    while(!q.empty())
    {
        int sz =q.size();

        while(sz--)
        {
            TreeNode* node =q.front();
            q.pop();

            if(!node->left && !node->right)return depth;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        depth++;
    }
    return depth;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode * root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    root -> right->right = new TreeNode(7);
    root -> right->left = new TreeNode(15);

    cout<<minDepth(root)<<endl;

    return 0;
}