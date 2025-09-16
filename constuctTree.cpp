#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data; 
    Node * left;
    Node * right;

    Node(int d)
    {
    this ->data = d;
    this ->left = NULL;
    this ->right = NULL;
    }
};


void createMapping(int in[], map<int,int>&nodeToIndex, int n)
{
    for(int i = 0; i<n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

Node* solve(int in[], int pre[], int& index, int inorderStart, int inorderEnd,int n ,map<int,int> & nodeToIndex)
{
    //base case
    if(index >= n || inorderStart > inorderEnd)
    {
        return NULL;
    }

    int element = pre[index++];

    Node* root = new Node(element);

    int position = nodeToIndex[element];


    //recursive call
    root->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);

    root->right = solve(in, pre, index, position + 1, inorderEnd ,n,nodeToIndex );

    return root;
}

Node * buildTree(int in[] , int pre[], int n)
{
    int preOrderIndex = 0;

    map<int,int>nodeToIndex;

    createMapping(in,nodeToIndex,n);


    Node* ans =solve(in ,pre,preOrderIndex, 0,n-1,n,nodeToIndex);
    return ans;
}

void printInOrder(Node* root)
{
    if(root == NULL)
    {
        return;

    }

    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);

}


int main()
{


    int in[] = {4, 2, 5, 1, 6, 3, 7};    // Inorder traversal
    int pre[] = {1, 2, 4, 5, 3, 6, 7};   // Preorder traversal
    int n = sizeof(in) / sizeof(in[0]);

    Node* root = buildTree(in ,pre,n);

    cout << "Inorder traversal of constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;

}