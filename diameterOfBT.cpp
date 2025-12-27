#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int diameter = 0;

int height(Node *root)
{

    // we have to return the length of the binary tree

    // Diameter : Length of the longest path between any two nodes in the tree

    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    // Updatinng diameter at this node
    diameter = max(diameter, lh + rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(Node *root)
{
    height(root);
    return diameter;
}

int main()
{

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}