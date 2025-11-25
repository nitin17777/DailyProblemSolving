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

void inorderHelper(Node *root, vector<int> &result)
{
    // we have to return the inorder Traversal of its nodes' values
    if (root == NULL)
        return;

    inorderHelper(root->left, result); // visiting left subtree

    result.push_back(root->data); // pushing root's data

    inorderHelper(root->right, result); // visiting right subtree
}

vector<int> inorderTraversal(Node *root)
{

    // we have to return the inorder Traversal of its nodes' values
    vector<int> result;

    inorderHelper(root, result);

    return result;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(3);

    vector<int> ans = inorderTraversal(root);

    for (auto &num : ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
