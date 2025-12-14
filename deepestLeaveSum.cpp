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
        this->left = NULL;
        this->right = NULL;
    }
};

// BFS Solution
int deepestLeavesSum(Node *root)
{
    // Return the sum of values of it's deepest leaves

    if (root == NULL)
        return 0;
    queue<Node *> q;

    q.push(root);

    int sum = 0;

    while (!q.empty())
    {
        int size = q.size();
        sum = 0;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            sum += node->data;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return sum;
}

int deepestLeavesSum(Node *root)
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}