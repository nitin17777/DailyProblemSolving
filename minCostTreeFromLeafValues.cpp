#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    Node* left;
    Node* right;

    int data;

    Node(int data)
    {
        this->data= data;

        this->left = NULL;
        this->right = NULL;
    }
};

    int mctFromLeafValues(vector<int>& arr)
    {
        //given an array of positive integers
        //each node has either 0 or 2 childrens


        //values of arr corresponds to values of each leaf in inorder traversal of tree

        //val of each non leaf node is equal to product of largest leaf value in it's left and right subtree

        //among all considered binary tress , return the smallest possible sum of values of each non leaf node 


        

    }






int main()
{

    Node* roo
    return 0;
    
}
