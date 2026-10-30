#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d)
    {
        this->val = d;
        this ->right = NULL;
        this ->left = NULL;    
    }
};

vector<vector<int>>verticalTraversal(TreeNode* root)
{

    vector<vector<int>>ans;

    //Stores col , row and value of nodes
    vector<tuple<int,int,int>>nodes;


    //Stores node, row and column
    queue<tuple<TreeNode*,int,int>>q;
    q.push({root,0,0});

    while(!q.empty())
    {
        auto[node,row,col] = q.front();
        q.pop();

        nodes.push_back({col,row,node->val});

        //Inc on right and dec on left
        if(node->left)q.push({node->left,row+1,col-1});
        if(node->right)q.push({node->right,row+1,col+1});
    }


    //col > row > val  : priority
    sort(nodes.begin(),nodes.end());

    int prevCol = INT_MIN;
    for(auto[col,row,val]:nodes)
    {
        if(col!=prevCol)
        {
            
            ans.push_back({});
            prevCol = col;
        }
        ans.back().push_back(val);
    }
    
    return ans;
}

int main()
{

    TreeNode* root= new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    vector<vector<int>>ans = verticalTraversal(root);

    for(auto&x:ans)
    {
        for(auto &y:x)cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}