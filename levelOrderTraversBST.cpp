#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    Node *right;
    Node *left;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> levelOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return {};

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        ans.push_back(node->data);

        if (node->right)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return ans;
}
