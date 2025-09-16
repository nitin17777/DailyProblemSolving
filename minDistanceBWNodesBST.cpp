#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int d)
    {
        this ->data = d;
        this ->data = NULL;
        this ->right = NULL;

    }
};

int minDiff(Node * root)
{
    int min = 0;

    



}

int main()
{
    Node * root = new Node(4);
    root ->left = new Node(2);
    root ->left ->left = new Node(1);
    root ->left ->right = new Node(3);

    root ->right = new Node(6);

    int ans =  minDiff(root);

    cout<<ans<<endl;
    
    return 0;

}