#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode *right;
    TreeNode *left;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int helper(TreeNode *root, int curr)
{
    if (!root)
        return 0;
    curr = curr * 10 + root->data;

    if (!root->left && !root->right)
        return curr;

    return helper(root->left, curr) + helper(root->right, curr);
}

int sumNumbers(TreeNode *root)
{

    // we have to return the sum of all root to leaf numbers
    return helper(root, 0);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << sumNumbers(root) << endl;

    return 0;
}
