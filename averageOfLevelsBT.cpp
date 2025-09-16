#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    Node* right;
    Node* left;
    int data;


    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<double> averageOfLevels(Node* root)
{

    //we have to return the average of values at same level

    vector<double>result;

    if(!root)
    {
        return result;
    }
    
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        int levelSize = q.size();
        long long levelSum = 0;

        //Processing all current level nodes
        for(int i = 0; i < levelSize; i++)
        {
            Node* node = q.front();
            q.pop();

            levelSum += node->data;
        
            if(node->left)
            q.push(node->left);
        
            if(node->right)
            q.push(node->right);   
        }

        result.push_back((double)levelSum / levelSize);
    }
    return result;
}

int main()
{
    Node * root = new Node(3);
    root->left= new Node(9);

    root->right= new Node(20);
    root->right->left= new Node(15);
    root->right->right= new Node(7);


    vector<double>result = averageOfLevels(root);

    for(auto & an :result)
    {
        cout<<an<<" ";
    }
    cout<<endl;
    
    return 0;

}