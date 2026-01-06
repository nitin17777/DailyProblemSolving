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
        this->right = NULL;
        this->left = NULL;
    }
};

/*

int maxLevelSum(Node* root)
{
    if(!root)return 0;

    int maxSum=INT_MIN;
    int level = 0,ans=0;


    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        level++;
        int size = q.size();
        int sum = 0;

        for(int i = 0;i<size;i++)
        {
            Node* curr = q.front();
            q.pop();

            sum +=curr->data;

            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }

        if(sum > maxSum)
        {
            maxSum = sum;
            ans = level;
        }

    }
    return ans;
}

*/

// Recursive approach

void dfs(Node *root, int level, vector<int> &sums)
{

    if (!root)
        return;

    // While visitin the level for first time
    if (level == sums.size())
        sums.push_back(root->data);

    else
    {
        sums[level] += root->data;
    }

    dfs(root->left, level + 1, sums);
    dfs(root->right, level + 1, sums);
}

int maxLevelSum(Node *root)
{
    vector<int> sums;
    dfs(root, 0, sums);

    int maxSum = INT_MIN;
    int ans = 0;

    for (int i = 0; i < sums.size(); i++)
    {
        if (sums[i] > maxSum)
        {
            maxSum = sums[i];
            ans = i + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(1);
    root->right = new Node(0);
    root->left = new Node(7);
    root->left->right = new Node(-8);
    root->left->left = new Node(7);

    cout << maxLevelSum(root) << endl;

    return 0;
}