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

void inorder(Node *root, vector<int> &res)
{
    if (!root)
        return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

vector<int> getAllElements(Node *root1, Node *root2)
{

    // we have to return all the elements present in given BST

    vector<int> t1, t2;

    inorder(root1, t1);
    inorder(root2, t2);

    vector<int> ans;

    merge(t1.begin(), t1.end(), t2.begin(), t2.end(), back_inserter(ans));

    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{

    Node *root1 = new Node(2);
    root1->left = new Node(3);
    root1->right = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(0);
    root2->right = new Node(3);

    vector<int> ans = getAllElements(root1, root2);
    for (auto &an : ans)
        cout << an << " ";

    return 0;
}
