#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node*left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;

    }
};

vector<int> preorderTraversal(Node* root)
{
    if(root == NULL)return {};
    vector<int>ans;

    ans.push_back(root->data);
    vector<int>left = preorderTraversal(root->left);
    vector<int>right = preorderTraversal(root->right);

    ans.insert(ans.end(), left.begin(), left.end());
    ans.insert(ans.end(), right.begin(), right.end());

    return ans;


}


int main()
{

     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);


    vector<int>ans = preorderTraversal(root);

    for(auto&an:ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;

}