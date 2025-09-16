#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node * left;

    Node(int d)
    {
        this ->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};



Node * minVal(Node* root)
{

    Node * temp = root;
    while(temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node * temp = root;
    while(temp && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}


Node * deleteNode(Node* root,int val)
{
    if(root == NULL)
    return root;

    if(val <root ->data)
    {
        root->left = deleteNode(root->left,val);
    }
    else if(val > root ->data)
    {
        root ->right=  deleteNode(root->right,val);
    }

    else
    {
        // Node with 0 or 1 child
        if(root ->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
            
        }
        else if(root ->right == NULL)
        {
            Node* temp = root ->left;
            delete root;
            return temp;

        }

        //when the node has 2 childrens
        Node* minNode = minVal(root->right);
        root ->data = minNode->data;

        root->right = deleteNode(root->right,root->data);

    }
    return root;

}

Node* takeInput()
{
    Node * root = NULL;

    int n;
    cin>>n;
    
    cout<<"Enter the nodes: ";
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left);

    cout<<root->data<<" ";
    inorder(root->right);
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

    int val = 3;

    root = deleteNode(root,val);

    cout<<"Inorder after deletion: ";
    inorder(root);

    cout<<endl;

    return 0;
}