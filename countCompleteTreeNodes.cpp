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
        this->right = NULL;
        this->left = NULL;
        this->data = data;
    }
};

int leftHeight(Node *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->left;
    }
    return h;
}

int rightHeight(Node *node)
{
    int h = 0;
    while (node)
    {
        h++;
        node = node->right;
    }
    return h;
}

int countNodes(Node *root)
{
    // we just have to count the number of nodes present in the tree

    if (!root)
        return 0;

    int lh = leftHeight(root);
    int rh = leftHeight(root);

    // if tree is perfect
    if (lh == rh)
    {
        return (1 << lh) - 1; // 2^lh - 1 Nodes
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);

    cout << countNodes(root) << endl;

    return 0;
}
