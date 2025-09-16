#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* right;
    Node * left;

    Node(int data)
    {
        this ->data =data;
        this->right = NULL;
        this->left = NULL;
    }
};

int minDepth(Node* root)
{
    if(root == NULL)return 0;

    if(root ->right == NULL && root->left == NULL)return 1;

    
}


int main()
{
    return 0;
    
}
