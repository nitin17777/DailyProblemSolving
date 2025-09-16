#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;

    }
};


Node*front;


bool check(Node*curr)
{

    //Base case when current is NULL
    if(!curr)return true;

    if(!check(curr->next))return false;

    if(curr->val != front->val)
    return false;

    front = front->next;

    return true;

}

bool isPal(Node*head)
{

}

int main()
{
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(2);
    root->next->next->next = new Node(1);

    if(isPal(root))
    {
        cout<<"Is Palindrome."<<endl;

    }
    else
    {
        cout<<"Is not a Palindrome."<<endl;
    }

    return 0;

}