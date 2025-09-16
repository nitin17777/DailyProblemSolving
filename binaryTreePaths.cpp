#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};



void contructPaths(Node* root ,string path,vector<string>& ans)
{
    if(root == NULL)
    return;

    path += to_string(root->data);

    if(root ->left == NULL && root ->right == NULL)
    {
        ans.push_back(path);
        return;
    }
    path += "->";

    contructPaths(root->left, path, ans);
    contructPaths(root ->right, path, ans);
}

vector<string> binaryTreePaths(Node* root)
{
    vector<string>ans;

    contructPaths(root,"",ans);// "" because we are staritng with an empty string 
    return ans;

}

int main()
{
    Node* root = new Node(1);
    root ->left = new Node(2);
    root->left ->right = new Node(5);
    root->right = new Node(3);

    vector<string>ans = binaryTreePaths(root);

    for(auto& path : ans)
    {
    cout<<path<<endl;
    }

    return 0;
    
}
