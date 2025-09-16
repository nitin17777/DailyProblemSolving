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
//check if the sum of left part and right part is equal to the root node for every possible node


pair<bool,int> isSumTreeFast(Node* root)
{
    //base case
    if(root == NULL)
    {
        pair<bool,int>p = make_pair(true,0);
    }

    if(root->left == NULL && root ->right == NULL)
{
    pair<bool,int>p = make_pair(true,root->data);
    return p;

}

pair<bool,int>leftAns = isSumTreeFast(root->left);
pair<bool,int>rightAns = isSumTreeFast(root->right);

bool isleftSumTree = leftAns.first;
bool isRightSumTree = rightAns.first;

int leftSum = leftAns.second;
int rightSum = rightAns.second;

bool condn = root ->data == leftSum + rightSum;

pair<bool,int>ans;

if(isleftSumTree && isRightSumTree && condn)
{
    ans.first = true;
    ans.second = root->data + leftSum + rightSum;

}
else
{
    ans.first = false;
}
return ans;
}



bool isSumTree(Node* root )
{
    return isSumTreeFast(root).first;

}

int main()
{
    // Create first tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

   

    // Check if the trees are identical
    if (isSumTree(root))
    {
        cout << "Sum Tree." << endl;
    }
    else
    {
        cout << "Not a sum tree." << endl;
    }

    return 0;
}

