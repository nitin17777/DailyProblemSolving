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
        this ->left = NULL;
        this - >right = NULL;
    }
    
};

Node* createParentMapping(Node* root,int target ,map<Node*,Node*>&nodeToParent)
{
    Node* res = NULL;
    queue<Node*>q;
    q.push(root);

    nodeToParent[root]= NULL;



    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front ->data == target)
        {
            res = front;
        }

        if(front->left)
        {
            nodeToParent[front->left] = front;

            q.push(front->left);

        }

        if(front->right)
        {
            nodeToParent[front->right];
            q.push(front->right);

        }



    }
    return res;



}

void burnTree(Node * root, map<Node*,Node*>& nodeToParent)
{
    map<Node*,bool>visited;

    queue<Node*>q;

    q.push(root);
    visited[root] = true;

    int ans = 0;
    while(!q.empty())
    {
        int sizee = q.size();
        for(int i = 0;i<sizee;i++)
        {
            
        }
    }




}

int minTime(Node* root,int target)
{
    int ans = 0;
    map<Node* ,Node*>nodeToParent;
    Node * target = createParentMapping(rooot,target,nodeToParent);

    burnTree(targetNode,nodeToParent);
    
    return ans;


}


 


int main()
{

}