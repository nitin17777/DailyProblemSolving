#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    TreeNode *right;
    TreeNode *left;
    int data;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<TreeNode *> solve(int l, int r)
{

    vector<TreeNode *> res;

    if (l > r)
        res.push_back(NULL);
    return res;

    for (int i = l; i <= r; i++)
    {
        vector<TreeNode *> leftTree = solve(l, i - 1); // Using values less than i

        vector<TreeNode *> rightTree = solve(i + 1, r);

        // Combinig each left and right subtree, since every combination forms a unique BST

        for (TreeNode *left : leftTree)
        {
            for (TreeNode *right : rightTree)
            {
                TreeNode *root = new TreeNode(i);

                root->left = left;
                root->right = right;

                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode *> generateTrees(int n)
{
    // We have to return all structurally unique BST which having  exactly n TreeNodes

    if (n == 0)
        return {};

    return solve(1, n);
}

int main()
{
    vector<TreeNode *> ans = generateTrees(3);

    return 0;
}
