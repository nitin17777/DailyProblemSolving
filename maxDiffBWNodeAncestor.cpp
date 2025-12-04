#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int ans = 0;

void dfs(TreeNode *node, int mn, int mx)
{
    if (node == NULL)
        return;

    ans = max(ans, max(abs(node->val - mn), abs(node->val - mx)));

    mn = min(mn, node->val);
    mx = max(mx, node->val);

    dfs(node->left, mn, mx);
    dfs(node->right, mn, mx);
}

int maxAncestorDiff(TreeNode *root)
{
    // return the max difference between ancestor and child

    ans = 0;
    dfs(root, root->val, root->val);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
    }

    return 0;
}