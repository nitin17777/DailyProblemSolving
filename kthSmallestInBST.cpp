#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Node
{
    Node* right;
    Node* left;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;

    }
    
};


void inorder(Node* root,vector<int>&result)
{
    if(root == NULL)
    return;

    inorder(root->left,result);
    result.push_back(root->data);
    inorder(root->right,result);
}

    int kthSmallest(Node* root, int k)
    {
        //we have to find the kth smallest element(1-indexed) in given Binary Search Tree

        //do inorder sort and simply return the required index

        vector<int>result;


        inorder(root,result);

     //   sort(result.begin(), result.end());   no need because inorder of bst is already sorted


        int ans = result[k-1];

        return ans;


    }


int main()
{
    Node* root = new Node(3);
    root->left= new Node(1);
    root->left->right= new Node(2);
    root->right= new Node(4);

    int k = 1;

    int ans= kthSmallest(root,k);

    cout<<ans<<endl;
}

