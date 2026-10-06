#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

int dfs(TreeNode* node,int mn)
{
    if(!node)return 0;

    if(node->val > mn)return node->val;


    int left = dfs(node->left,mn);
    int right = dfs(node->right,mn);

    if(left == -1)return right;
    if(right == -1)return left;

    return min(left,right);
}


int findSecondMinimumValue(TreeNode* root)
{
    //We need to output the second minimum value of all the nodes in the whole tree

    int mn = root->val;

    int ans = dfS(root,mn);
    return ans;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    
    }

    return 0;
}