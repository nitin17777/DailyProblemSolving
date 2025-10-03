#include <iostream>
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

void inorder(Node *root)
{

    Node *current;
    if (!root)
        return;

    inorder(root->left);

    root->left = NULL; // removing left child

    current->right = root; // link it as right child

    current = root;

    inorder(rooot->right);
}

Node *increasingBST(Node *root)
{

    Node *dummy = new Node(-1);
}

int main()
{
}