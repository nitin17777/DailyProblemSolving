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
        this->left = NULL;
        this->right = NULL;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<Node *> q;

    q.push(root);

    // until all the nodes are processed
    while (!q.empty())
    {
        int levelSize = q.size();

        vector<int> level;

        for (int i = 0; i < levelSize; i++)
        {
            Node *node = q.front();
            q.pop();

            level.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        ans.push_back(level);
    }

    return ans;
}

int main()
{

    Node *root = new Node(3);
    root->right = new Node(20);
    root->right->right = new Node(7);
    root->right->left = new Node(15);

    root->left = new Node(9);

    vector<vector<int>> ans = levelOrder(root);

    for (auto &an : ans)
    {
        for (auto &a : an)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}
