#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right =NULL;
    }
};

Node*LCAinBST(Node* root,Node* P,Node*Q)
{

    while(root!=NULL)
    {
        if(root ->data < P->data && root->data < Q->data)
        {
            root = root->right;

        }

        else if(root ->data > P->data && root->data > Q->data)
        {
            root = root->left;

        }
        else
        {
            return root;
            
        }
        
    }
    return NULL;


    /*
    //base case
    if(root == NULL)
    return NULL;


if(root ->data < P->data && root->data < Q->data)
{
    return LCAinBST(root->right,P,Q);
    
}


if(root ->data > P->data && root->data > Q->data)
{
    return LCAinBST(root->left,P,Q);
    
}

return root;
*/

}


    int main()
{

    Node* root = new Node(4);
    root ->left = new Node(2);
    root ->left ->left = new Node(1);
    root->left ->right = new Node(3);

    root->right = new Node(7);
    root ->right->left = new Node(6);
    root ->right ->right = new Node(9);


    Node* P =root->left->right;
    Node* Q = root->right->left;

    Node* ans = LCAinBST(root,P,Q);

    if(ans)
    {
        cout<<"LCA: "<<ans->data<<endl;

    }

    else
    {
        cout<<"LCA not found."<<endl;
    }
    
    return 0;

}



