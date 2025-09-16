#include<iostream>
#include<climits>
using namespace std;

struct Node
{
    Node* left;
    Node*right;

    int val;

    Node(int val)
    {
        this->val = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};



    int maxGain(Node* root, int & maxSum)
    {

        if(!root)
        return 0 ;

        int leftG = max(maxGain(root->left, maxSum), 0);
        int rightG = max(maxGain(root->right,maxSum), 0);

        int currentPathSum = root->val + leftG + rightG;


        maxSum = max(currentPathSum, maxSum);

        return root->val + max(leftG , rightG); // total max sum this node can give to it's parent node

    }

    int maxPathSum(Node* root)
    {
        //we have to find the max possible sum of path in given binary tree
        int maxSum = INT_MIN;
        return maxGain(root,maxSum);

        return maxSum;
    }



int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);


    int ans = maxPathSum(root);

    cout<<ans<<endl;

    return 0;

}