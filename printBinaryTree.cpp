#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct TreeNode {
    int data;
    TreeNode* next;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val) {
        data = val;
        next = NULL;
        this->right = NULL;
        this->left = NULL;
    }
};

vector<vector<string>> printTree(TreeNode* root)
{
    vector<vector<string>>ans();


}




      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);


    vector<vector<string>>ans = printTree(root);


    return 0;
}