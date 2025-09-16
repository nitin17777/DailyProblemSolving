#include<iostream>
using namespace std;

struct Node
{
    Node* left;
    Node*right;

    int data;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;

    }
};


void dfs(Node* root, int targetSum, vector<int>path,<vector<vector<int>>result)
{
    if(!node)
    return;

    path.push_back(node->data); // when we will reach here it will be sure that node won't be null

    targetSum -= node->data;

    //when we reach the final leaft node of the path
    if(node->left == NULL && node->right == NULL && targetSum == 0)
    {
        result.push_back(path);
    }

    dfs(node->left,targetSum,path,result);
    dfs(node->right,targetSum,path,result);

    path.pop_back(); //so that we can now search for another path if present
    


}


vector<vector<int>> pathSum(Node* root, int targetSum)
{

    vector<vector<int>>result;
    vector<int>path;

    dfs(root,targetSum,path,result);

    return result;
    //we are given a target sum . we have to return all the paths whose sum of nodes equals target sum


    //for that ,we have to go and check every path whether if it can sum up to the target or not!!

}
        


int main()
{




    return 0;

}