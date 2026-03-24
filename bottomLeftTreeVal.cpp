#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;


    TreeNode(int data)
    {
        this->val = data;
        this->right = NULL;
        this->left = NULL;
    }
};

int findBottomLeftValue(TreeNode* root)
{
    if(!root)return 0;

    //Just find the left of last level

    queue<TreeNode*>q;
    q.push(root);

    //Storing the left of current node 
    int ans = root->val;

    while(!q.empty())
    {
        int sz = q.size();

        for(int i = 0;i<sz;i++)
        {
            TreeNode* node = q.front();
            q.pop();

            //First node processed in this level is the leftmost node of that level
            if(i==0)ans = node->val;

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return ans;
}



//DFS Approach now
int result = 0,maxDepth = -1;

void dfs(TreeNode* node,int depth)
{
    if(!node)return;

    if(depth > maxDepth)
    {
        maxDepth = depth;
        result = node->val;
    }
    dfs(node->left,depth+1);
    dfs(node->right,depth+1);
}


int findBottomLeftValue2(TreeNode* root)
{
    dfs(root,0);
    return result;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout<<findBottomLeftValue(root)<<endl;

    return 0;
}