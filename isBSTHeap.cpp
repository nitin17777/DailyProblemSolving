#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this ->right = NULL;
    }


};

int countNodes(Node* root)
{
    if(root == NULL)
    return 0;

    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(Node* root,int index, int cnt)
{
    if(root == NULL)
    return true;

    if(index >= cnt)
    return false;

    else
    {
        bool left = isCBT(root->left, 2* index+1, cnt);
        bool right = isCBT(root->right, 2* index + 2, cnt);
        return (left && right);
    }
}


bool isMaxOrder(Node* root)
{
    //leaf Node
    if(root->left == NULL && root->right == NULL)
    return true;

    if(root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->data > root->left->data && root->data >root ->right ->data ));
    }
}


bool isHeap(Node* root)
{
    int index = 0;
    int totalCount = countNodes(root);

    if(isCBT(root,index,totalCount) && isMaxOrder(root))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if (isHeap(root)) {
        cout << "The binary tree is a Max-Heap" << endl;
    } else {
        cout << "The binary tree is NOT a Max-Heap" << endl;
    }

    return 0;
}