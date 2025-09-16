#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node *right;

    Node(int d)
    {
        this->right = NULL;
        this-> left = NULL;
        this ->data = d;
    }
};

void inorder(Node* root, vector<int>& in)
{
    if(root == NULL)
    return ;

    inorder(root->left ,in);
    in.push_back(root->data);
    inorder(root ->right, in);

}


bool twoSumBST(Node *root ,int target)
{
    vector<int>inorderVal;


    //store inorder to get sorted values
    inorder(root,inorderVal);

    //now using two pointer approach to check if the pair sum exists
    int i = 0, j = inorderVal.size()-1;

    while(i<j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target)
        return true;

        else if(sum > target)
        j--;

        else 
        i++;

    }
    return false;



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

    int target = 7;
    //int ans = twoSumBST(root,target);

    if(twoSumBST(root,target))
    {
        cout<<"True"<<endl;

    }
    else{
        cout<<"False"<<endl;
    }


    return 0;
    
}