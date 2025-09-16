#include<bits/stdc++.h>
using namespace std;


class Node
{
    public:
    Node * left;
    Node* right;
    int data;


    Node(int data)
    {
    this->data= data;
    left = NULL;
    right = NULL;
    }
};

class cmp
{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a->data > b->data; //to make our priority queue behave like minHeap
        //thus we ar emaking smaller frequencies to come up first
    }
};

class Solution
{
    public:

    void traverse(Node* root, vector<string>& ans,string temp)
    {

        //base case

        if(!root->left && !root->right)
        {
            ans.push_back(temp);
            return;
        }

        traverse(root ->left, ans, temp + '0');
        traverse(root ->right, ans, temp + '1');
    }
    
    vector<string>huffmanCodes(string S,vector<int>f,int N)
    {
        priority_queue<Node* ,vector<Node*>, cmp>pq;

        for(int i = 0; i<N; i++)
        {
            Node* temp = new Node(f[i]);
            pq.push(temp);
        }

        while(pq.size() > 1)
        {
            Node* left = pq.top();
            pq.pop();

            Node * right = pq.top();
            pq.pop();


            Node* newNode = new Node(left ->data + right->data);

            newNode ->left = left;
            newNode ->right = right;

            pq.push(newNode);
        }

        Node* root = pq.top();

        vector<string>ans;
        string temp= "";
        traverse(root,ans,temp);

        return ans;
    }
};

     

int main()
{
    string S ="abcdef";
    int N = 6;
    
    vector<int>f = {5,9,12,13,16,45};

    Solution obj;

    vector<string>ans = obj.huffmanCodes(S,f,N);

    for(auto code:ans)
    {
        cout<< code <<" ";

    }
    cout<<endl;

    return 0;

}
