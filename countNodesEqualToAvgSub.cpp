#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int data;
    Node* left;
    Node*right;

    Node(int val) {
        data = val;
        right = NULL;
        left = NULL;
    }
};

int ans=0;

pair<int,int>dfs(TreeNode* root)
{
    if(node == NULL)return {0,0};

    //sum and count from left and right subtree
    auto left = dfs(node->left);
    auto right = dfs(node->right);


    //Sum and count of current subtree
    int sum = node->val + left.first + right.first;
    int count = 1 + left.second + right.second;

    if(node->val == sum/count)ans++;

    return {sum,count};
}


int averageOfSubtree(TreeNode* root) 
{

    //Return the number of nodes with value equal to average of values in it's subtree


    //average = 

    //just do recursion : new average = left+ right + node value / 3

    dfs(root);
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