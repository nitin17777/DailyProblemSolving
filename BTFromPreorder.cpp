#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    TreeNode *right;
    TreeNode *left;

    int data;

    TreeNode(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int idx = 0;
TreeNode *build(vector<int> &preorder, int bound)
{
    // Base case to prevent out of range and handle violating constraints
    if (idx == preorder.size() || preorder[idx] > bound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx++]);

    root->left = build(preorder, root->data);
    root->right = build(preorder, bound);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &pre)
{
    return build(pre, INT_MAX);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}