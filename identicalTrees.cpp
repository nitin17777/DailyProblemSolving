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
    this ->right =NULL;
    this->left = NULL;
    }
};


bool isIdentical(Node* r1,Node* r2)
{

    //base case
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    if(r1 != NULL && r2 == NULL)
    {
        return false;
    }
    if(r1 == NULL && r2 != NULL)
    {
        return false;
    }

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main()
{
    // Create first tree
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Create second tree
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    // Check if the trees are identical
    if (isIdentical(root1, root2))
    {
        cout << "Both trees are identical." << endl;
    }
    else
    {
        cout << "Trees are not identical." << endl;
    }

    return 0;
}
