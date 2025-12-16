#include<bits/stdc++.h>
using namespace std;

Node*build(vector<int>&pre,int bound)
{
    int idx = 0;
    // Base case to prevent out of range and handle violating constraints
    if(idx == pre.size() || pre[idx] == bound)return NULL;

    Node* root = new Node(preorder[idx++]);

    root->left = build(pre,root->data);
    root->right = build(pre,bound);

    return root;
}

Node* bstFromPreorder(vector<int>& pre)
{
    return build(pre,INT_MAX);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vect

    




    return 0;
    
}