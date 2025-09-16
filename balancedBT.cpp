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
// a balanced binary is such that depth of two subtrees of every node never differs by more than one

int checkHeight(Node * root)
{

    if(root == NULL)
    {
        return 0;;
    }

    int leftHeight = checkHeight(root->left);
    int rightHeight = checkHeight(root->right);

    if(leftHeight == -1)
    return -1;

    if(rightHeight == -1)
    return -1;

    if(abs(rightHeight - leftHeight) > 1)
    {
        return -1;

    }
    else
    {
        return(max(leftHeight,rightHeight) +1);

    }
}

    bool isBalanced(Node* root)
    {
        return checkHeight(root) != -1; //if the tree is unbalanced we will get true

    }

int main()
{

    Node* root = new Node(3);
    root ->left = new Node(9);
    root->right = new Node(20);
    root ->right->left = new Node(15);
    root ->right ->right = new Node(7);

    if (isBalanced(root))
    {
        cout<<"Tree is balanced."<<endl;

    }
    else{
        cout<<"Tree is unbalanced."<<endl;
    }

    return 0;

}
