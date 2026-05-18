#include<bits/stdc++.h>
#define ll long long
using namespace std;


TreeNode* searchBST(TreeNode* root, int val)
{

    while(root != NULL)
        {
            if(root->val == val)
                return root;

            else if(val < root->val)
                root = root->left;

            else
                root = root->right;
        }
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