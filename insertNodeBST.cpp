#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this ->data = d;
        this ->left = NULL;
        this ->right = NULL;
    }
};


Node * insertNode(Node* root,int d)
{
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
    {
        root->right = insertNode(root->right,d);

    }
    else
    {
        root->left = insertNode(root->left,d);
    }

    return root;

}

void inorder(Node* root)
{
    if(root == NULL)
    return ;

    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);

}

void levelOrder(Node* root)
{

    if(root == NULL)
    {
        return;

    }

    queue<Node*>q; //queue to store nodes of each level

    q.push(root); // starting by pushing the root


    while(!q.empty()) //loop unitl queue becomes empty
    {
        Node* current = q.front();
        q.pop();

        cout<<current->data<<" ";
        
        if(current->left != NULL) // if left child exists,add it to the queue
        {
            q.push(current->left);

        }

        if(current->right != NULL)
        {
            q.push(current ->right);

        }

    }
}


int main()
{
    vector<int> arr = {4,2,7,1,3};

    Node* final = NULL;

    for(auto& num : arr)
    {
        final = insertNode(final,num);
    }

    cout<<"Printing BST in inorder: ";
    inorder(final);
    cout<<endl;

    cout<<"Printing BST in in levelorder: ";
    levelOrder(final);
    cout<<endl;
    

    return 0;

}
