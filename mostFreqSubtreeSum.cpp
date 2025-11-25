#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->left = NULL;
        this->right = NULL;
        this->data = data;
    }
};

unordered_map<int, int> freq;

int subTreeSum(Node *root)
{
    if (root == NULL)
        return 0;
    int left = subTreeSum(root->left);
    int right = subTreeSum(root->right);

    int sum = left + right + root->data;

    freq[sum]++;
    return sum;
}

vector<int> findFrequentTreeSum(Node *root)
{
    // we have to return the most frquent subtree sum()

    freq.clear();
    subTreeSum(root);

    int maxFreq = 0;
    for (auto &p : freq)
    {
        maxFreq = max(maxFreq, p.second);
    }

    vector<int> ans;

    for (auto &p : freq)
    {
        if (p.second == maxFreq)
        {
            ans.push_back(p.first);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(-3);
    vector<int> ans = findFrequentTreeSum(root);
    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}
