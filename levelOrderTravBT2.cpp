#include <bits/stdc++.h>
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

vector<vector<int>> levelOrderBottom(Node *root)
{

    // We have to return bottom-up level order traversal

    vector<vector<int>> result;

    if (root == NULL)
        return result;

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        vector<int> level;

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            level.push_back(node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_back(level);
    }
    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(3);
    root->right = new Node(20);
    root->right->right = new Node(7);
    root->left = new Node(9);
    root->right->left = new Node(15);

    vector<vector<int>> ans = levelOrderBottom(root);
    for (auto &an : ans)
    {
        for (auto &a : an)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}