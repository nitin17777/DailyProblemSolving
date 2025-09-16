#include<iostream>
using namespace std;

struct Node
{
    Node* left;
    Node*right;

    int data;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;

    }
};


 int maxDepth(Node* root)
    {
        //we have to count the max depth of binary tree ie from node to leaf
        

        if(root == NULL)
        return 0;

        //case of leaf node
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int ans = 1 + max(left,right);

        return ans;
   
    }


int main()
{
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->right = new Node(7);
    root->right->left = new Node(15);

    int ans = maxDepth(root);

    cout<<ans<<endl;



    return 0;

}