#include<iostream>
using namespace std;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int data;

    TreeNode(int data)
    {
        this->left = NULL;
        this->right =  NULL;
        this ->data = data;


    }
    
};


int sumL(TreeNode* root)
{
    //we have to find the sum of all left leaves present in the given binary tree

    int sum =0;

    if(root == NULL)
    return 0;

    if(root->left) //if left of root exists
    {
       //checking if left child is leaf or not
       if(root->left->left == NULL && root ->left ->right == NULL)
       {
        sum += root->left->data;
       }
    }

    sum+=sumL(root->left);
    sum+=sumL(root->right);

    return sum;

}

int main()
{

    TreeNode* root = new TreeNode(30);
    root->left = new TreeNode(9);

    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);

    cout<< sumL(root)<<endl;
    
    return 0;

}