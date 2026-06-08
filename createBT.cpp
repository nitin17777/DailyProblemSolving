#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        right = NULL;
        left = NULL;
    }
};

TreeNode* createBinaryTree(vector<vector<int>>& des)
{

    //Construct the requried bianry tree

    unordered_map<int,TreeNode*>nodes;
    unordered_set<int>childs;

    for(auto &x:des)
    {
        int parent = x[0];
        int child = x[1];
        int isLeft = x[2];
        
        if(nodes.find(parent) == nodes.end())nodes[parent] = new TreeNode(parent);

        if(nodes.find(child) == nodes.end())nodes[child] = new TreeNode(child);

        if(isLeft)nodes[parent]->left = nodes[child];
        
        else nodes[parent]->right = nodes[child];

        childs.insert(child);

    }

    for(auto &[val,node] : nodes)
    {
        //if any node is noone's child, then it would be parent node
        if(childs.find(val) == childs.end())return node;
    }1
    return NULL;
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