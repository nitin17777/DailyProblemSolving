#include<iostream>
#include<vector>
using namespace std;



class Node

{
    public: 
    
    int data;
    Node* right;
    Node * left;

    Node(int data)
    {
        this->data = data;
        this ->right = NULL;
        this ->left = NULL;
    }
};


bool isSameTree(Node* p, Node*q)
{

    //we are given two trees, we have to check whether both are same or not

    //starting with base case :
    if(p == NULL && q == NULL)
    return true;

    if(q == NULL || p == NULL)
    return false;

    if(p->data != q->data)
    return false;

    return isSameTree(p->left ,q->left) &&isSameTree(p ->right , q->right);


}

int main()
{

    Node*p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    if(isSameTree(p,q))
    cout<<"Same Tree."<<endl;

    else
    cout<<"Different Tree." <<endl;

    return 0;

}