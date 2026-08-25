#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        right = NULL;
        left = NULL;
    }
};

int widthOfBinaryTree(Node* root)
{
    //We have to return the max width of given tree : bw 2 non null nodes

    if(root== NULL)return 0;


    //queue stores: (node,index) :index is position this node would occupy in binary tree
    queue<pair<Node*,ll>>q;
    q.push({root,0});
    int ans=0;

    while(!q.empty())
    {
        int sz = q.size();

        ///All the nodes in queue belongs to the same level and first node's index represents leftmost occupied position
        ll firstIndex = q.front().second;
        
        ll right = 0,left = 0;

        for(int i=0;i<sz;i++)
        {
            auto[node,index] = q.front();
            q.pop();

            index-=firstIndex;

            //first node in this level is leftmost non null node
            if(i==0)left=index;
            if(i==sz-1)right= index;

            if(node->left)q.push({node->left,2*index});
            if(node->right)q.push({node->right,2*index+1});

            int width = right - left+1;
            ans =max(ans,width);
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    
    }

    return 0;
}