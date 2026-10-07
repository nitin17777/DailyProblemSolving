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
void recoverTree(TreeNode* root)
{

    //We are given a tree where values of exactly two nodes of tree we swapped by mistake

    TreeNode*fs = NULL;
    TreeNode* sec = NULL;
    TreeNode * prev = NULL;

    TreeNode* curr = root;

    while(curr)
    {
        if(!curr->left)
        {
            if(prev && prev->val > curr->val)
            {
                if(!first)first = prev;

                second = curr;
            }

            prev = curr;
            curr = curr->right;
        }


        else
        {

            
        }
    }

        
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