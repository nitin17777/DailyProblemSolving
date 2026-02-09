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

void inorder(Node *root, vector<Node *> nodes)
{
    if (root == NULL)
        return;
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

Node *build(vector<Node> *nodes, int l, int r)
{
    if (l > r)
        return NULL;

    int mid = (l + r) / 2;

    Node *root = nodes[mid];

    root->left = build(nodes, l, mid - 1);
    root->right = build(nodes, mid + 1, r);

    return root;
}

Node *balanceBST(Node *root)
{

    // Tree is called balanced if depth of two subtrees of very node never differs by more than 1

    vector<Node *> nodes;

    inorder(root, nodes);

    return build(nodes, 0, nodes.size() - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);

    Node *ans = balanceBST(root);

    return 0;
}