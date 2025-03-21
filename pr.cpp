#include<iostream>
using namespace std;


class NODE
{
    public:
    int data;
    Node* next;
    NOde(int data)
    {
        this->data = data;
        this->next= NULL;

    }
};


Node kRev(Node* head , int k)
{

    if(head == NULL)
    {
        return NULL;

    }

    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;


    //reversing first k nodes

    while( curr != NULL && count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;

    }


    //now recursion will handle
    if(next!=NULL)
    {
        head->next = kRev(next, k)

    }

    return rev;
    
}