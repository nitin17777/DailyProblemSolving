#include<bits/stdc++.h>
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
        this->right = NULL;
    }
};


bool isIdentical(Node*r1,Node* r2)
{

    //base case
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if(r1 == NULL && r2 != NULL)
    {
        return false;

    }

    if(r1 != NULL && r2 == NULL)
    {
        return false;
    }
}


bool left = isIdentical(r1->left,r2->left);

bool right = isIdentical(r2->right , r1->right);

bool value = r1->data == r2->data;

if(left && right && value)
{
    return true;

}
else
{
    return false;
}




pair<bool,int>isBalancedFast(Node* root)
{
    //base case
    if(root == NULL)
    {
        pair<bool,int>p = make_pair(true,0);
        return p;

    }
    pair<int,int>left =isBalancedFast(root ->left);
    pair<int,int>right =isBalancedFast(root ->right);


    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(leftAns - rightAns) <=1;

    pair<bool,int>ans;

    ans.second = max(left.second , right.second) +1;


    if(leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
    ans.first = false;
    }
    return ans;
}

bool isBalanced(Node* root)
{
    return isBalancedFast(root).first;

}


int height(Node* root)
{
    if(Node == NULL)
    {
        return 0;

    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = max(left,right)+1;

    return ans;

}

pair<int,int>diameterFast(Node* root)
{
    //base case
    if(root == NULL)
    {
        pair<int,int>p = make_pair(0,0);

        return p;
    }

    pair<int,int>left = diameterFast(root->left);
    pair<int,int>right = diameterFast(root ->right);

    int op1 = left.first;
    int op2 = right.first;


    int op3 = left.second + right.second;

    pair<int,int>ans;
    ans.first = max(op1, max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    
    return ans;
}
