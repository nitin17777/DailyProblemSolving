#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left,*right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<int>nums;

void inorder(TreeNode* root)
{
    if(!root)return;

    inorder(root->left);
    nums.push_back(root->data);
    inorder(root->right);
}

int minDiffInBST(TreeNode* root)
{
    inorder(root);

    int ans=INT_MAX;

    for(int i = 1;i<nums.size();i++)
    {
        ans = min(ans,nums[i]-nums[i-1]);
    }
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