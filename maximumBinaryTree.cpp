#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// to find the root node i.e the largest element in array
int maxIndex(vector<int>&nums, int start, int end)
{
    int maxIdx = start;
    for(int i = start;i <= end;i++)
    {
        if(nums[i] > nums[maxIdx])
        {
           maxIdx = i;
        }
    }
    return maxIdx;
}


Node * constructMax(vector<int>&nums,int start,int end)
{
    if(start > end)
    {
        return NULL;
    }

    int maxIdx = maxIndex(nums,start,end);

    Node* root = new Node(nums[maxIdx]);

    root->left = constructMax(nums, start, maxIdx-1);//left subtree is maximum of tree formed from left of the max 
    root->right = constructMax(nums, maxIdx+1, end);//right subtree is maximum of tree formed from right of the max 

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main()
{
    vector<int>nums = {3,2,1,6,0,5};

    Node* ans = constructMax(nums,0,nums.size()-1);
    cout<<"Max binary tree(inorder): ";

    inorder(ans);
    cout << endl;
    return 0;
}
