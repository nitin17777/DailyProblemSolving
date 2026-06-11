#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int dfs(TreeNode* root,int maxi)
{
    if(!root)return 0;
    
    int cnt = 0;

    if(root->data>=maxi)cnt=1;
    
    maxi = max(maxi,root->data);

    cnt+=dfs(root->left,maxi);
    cnt+=dfs(root->right,maxi);

    return cnt;
}

int goodNodes(TreeNode* root)
{

    /*

    good if -> path from root to that node does not have any node value > that current node value

    
    */
   return dfs(root,INT_MIN);
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