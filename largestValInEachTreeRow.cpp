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

vector<int> largestValues(Node *root)
{
    // we have to find the largest value in each row
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        int maxi = INT_MIN;

        while (size--)
        {
            Node *node = q.front();
            q.pop();

            maxi = max(maxi, node->data);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        ans.push_back(maxi);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(9);

    root->left->right = new Node(3);
    root->right->right = new Node(5);

    vector<int> ans = largestValues(root);
    for (auto &a : ans)
        cout << a << " ";

    cout << endl;

    return 0;
}