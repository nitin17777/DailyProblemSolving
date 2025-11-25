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

vector<Node *> generateTrees(int n)
{
    // We have to return all structurally unique BST which has exactuy n nodes
}
