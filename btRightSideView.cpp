#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* next;

    TreeNode(int val) {
        data = val;
        next = NULL;
    }
};

void dfs(TreeNode* root,vector<int>&ans)
{

    if(root->right)
    {
        root = root->right;

        ans.push_back(root->val);
        dfs(root,ans);
    }

}


vector<int> rightSideView(TreeNode* root)
{

    if(!root)return {};

    vector<int>ans;

    //Return the values we can see form right of the tree from top to botoom

    ans.push_back(root->val);
    dfs(root,ans);

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