#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this ->right = NULL;
        this ->left = NULL;    
    }
};

vector<int>zz(Node* root)
{

    vector<int>ans;

    if(root == NULL)
    {
        return ans;
    }

    queue<Node*>q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();

        vector<int>temp(size); //temporary array to store answers


        for(int i=0; i<size; i++)
        {
            Node * frontNode = q.front();
            q.pop();

            //normal insert or reverse insert
            int index = leftToRight ? i : size -1-i;

            temp[index] = frontNode ->data;


            if(frontNode ->left)
            {
                q.push(frontNode ->left);
            }

            if(frontNode ->right)
            {
                q.push(frontNode ->right);
            }
        }

        //direction change
        leftToRight = !leftToRight;
        for(auto i:temp)
        {
            ans.push_back(i);
        }

    }
    return ans;
}

    int main()
{
    // Create first tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int>aj = zz(root);

    for(int aa: aj)
    {
        cout<< aa <<" ";

    }

    cout<<endl;
}