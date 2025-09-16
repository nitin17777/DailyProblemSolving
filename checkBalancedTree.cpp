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



   /* int height(Node * root)
{
    if(root == NULL)
    {
        return 0;

    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;
}
    */

pair<bool,int>isBalancedFast(Node* root)
{

    if(root == NULL)
    {
        pair<bool,int>p = make_pair(true,0);
        return p;

        pair<int ,int>left = isBalancedFast(root->left);
        pair<int ,int>right = isBalancedFast(root->right);

    bool leftAns = left.first;

    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <=1;

    pair<bool,int> ans;
    ans.second = max(left.second,right.second) + 1;

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
}

bool isBalanced(Node* root)
{
    return isBalancedFast(root).first;

}


/*
bool isBalanced(Node* root)
{
    if(root ==NULL)
    {
        return true;

    }

    bool left = isBalanced(root->left);

    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right))<=1;


    if(left && right&& diff)
    {
        return 1;
        
    }
    else
    {
        return false;

    }
}
    */


 int main()
{

    Node* root = new Node(1);

    root ->left = new Node(2);
    root ->right = new Node(3);

    root-> left -> left = new Node(4);
    root ->left ->right = new Node(5);

    if(isBalanced(root))
    {
        cout<<"Binary Tree is balanced."<<endl;

    }
    else
{
    cout<<"Binary Tree is not balanced"<<endl;
}
    return 0 ;
}