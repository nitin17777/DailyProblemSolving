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

void inorder(Node *root, vector<int> res)
{
    if (root == NULL)
        return {};

    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

int getMinimumDifference(Node *root)
{
    // do traversal =>sort => itereate over found array
    vector<int> res;

    int maxDiff = INT_MAX;

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(res[i] - res[j]);
            maxDiff = min(diff, maxDiff);
        }
    }
    return maxDiff;
}
