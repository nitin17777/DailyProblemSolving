#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ts = 0;
ll maxi = 0;
const int MOD = 1e9 + 7;

struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

ll totalSum(Node *root)
{
    if (!root)
        return 0;

    return root->data + totalSum(root->right) + totalSum(root->left);
}

ll dfs(Node *root)
{

    if (!root)
        return 0;
    ll left = dfs(root->left);
    ll right = dfs(root->right);

    ll subtreeSum = root->data + left + right;

    ll product = subtreeSum * (ts - subtreeSum);

    maxi = max(maxi, product);
    return subtreeSum;
}

int maxProduct(Node *root)
{

    /*

    Split the BT such that : We have max products of sums of both the trees

    For max products it would be good if both have highest possible sum

    Max product would be when both the sums are closest

    */

    // So mark the subtree sum at each node

    ts = totalSum(root);
    dfs(root);

    return maxi % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << maxProduct(root) << endl;

    return 0;
}