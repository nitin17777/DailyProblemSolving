#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

int dfs(TreeNode *root, int curr)
{
    if (!root)
        return 0;

    curr = curr * 2 + root->val;

    if (!root->left && !root->right)
        return curr;

    return dfs(root->left, curr) + dfs(root->right, curr);
}

int sumRootToLeaf(TreeNode *root)
{

    // Traverse from root to all leaf TreeNodes -> a binary number would be formed and then add all those converted numbers
    return dfs(root, 0);

    // Find each path possible, and add
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(1);
    root->left = new TreeNode(0);

    root->left->right = new TreeNode(0);
    root->left->left = new TreeNode(0);

    root->right->right = new TreeNode(1);
    root->right->left = new TreeNode(0);

    cout << sumRootToLeaf(root) << endl;

    return 0;
}