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

vector<int>ans;

//DFS Approach
void dfs(TreeNode*root,int depth)
{

    if(!root)return;

    if(depth === ans.size())ans.push_back(root->val);

    //right subtree will be visited first
    dfs(root->right,depth+1);

    dfs(root->left,depth+1);
}

//BFS Approach
vector<int> bfs(TreeNode*root)
{

    vector<int>anss;

    if(root==NULL)return anss;


    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();

        for(int i = 0; i < n;i++)
        {
            TreeNode* node = q.front();
            q.pop();

            //last visible node of this level from right side
            if(i==n-1)anss.push_back(node->val);

            if(node->left != NULL)q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return ans;
}

vector<int> rightSideView(TreeNode* root)
{
    ans.clear();
    dfs(root,0);
    return ans;

}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}