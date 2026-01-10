#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

pair<int, Node *> dfs(Node *root)
{
    // In this case, node is NULL, depth is 0 and no subtree exists

    if (!root)
        return {0, NULL};

    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // Case 1: Left subtree is deeper than right
    if (left.first > right.first)
    {
        return {left.first + 1, left.second};
    }

    // Case 2: Right subtree is deeper than left
    if (right.first > left.first)
    {
        return {right.first + 1, right.second};
    }

    else
    {
        return {left.first + 1, root};
    }
}

Node *subtreeWithAllDeepest(Node *root)
{

    // We have to return the smallest subtree such that it contains all the deeepest nodes in the original tree

    // So we can return the deepest leaves along with it's root
    return dfs(root).second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(3);

    return 0;
}