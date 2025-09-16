#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node * left;
    Node* right;

    Node(int d)
    {
        this ->data = d;
        this ->right = NULL;
        this ->left = NULL;

    }
};
int height(Node * root)
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


pair<int,int>diameterFast(Node* root)
//int diameter(Node* root)
{
    if(root == NULL)
    {
        pair<int,int>p = make_pair(0,0);
        return p;


    }

    pair<int,int>left = diameterFast(root->left);
    pair<int,int>right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second +1;

    pair<int,int>ans;
    ans.first =max(op1,max(op2,op3));
    ans.second = max(left.second , right.second) + 1;
    return ans;

}

    int diameter(Node* root)
    {
        return diameterFast(root).first;

    }
int main()
{

    Node* root = new Node(1);

    root ->left = new Node(2);
    root ->right = new Node(3);

    root-> left -> left = new Node(4);
    root ->left ->right = new Node(5);

    int dia = diameter(root);

    cout<<"Diameter is "<<dia<<endl;




    return 0 ;

}