#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->right = NULL;
        this->left = NULL;
    }
};

Node *mergeTrees(Node *root1, Node *root2)
{
}

int main()
{
    return 0;
}