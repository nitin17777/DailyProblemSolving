#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this-> next=NULL;

    }
};


Node* kReverse(Node* head,int k)
{
    //base case
    if(head == NULL)
    {
        return NULL;

    }

    



//reverse first k nodes
    Node* next = NULL;
    Node * curr = head;
    Node *prev = NULL;

    int count = 0;
    

    while(curr != NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;

        curr = next;
        count ++;


    }

    //recursive call

    if(next != NULL)
    {
        head -> next = kReverse(next ,k);

    }


    return prev;
}

bool isCircular(Node* head)
{
    if(head == NULL)
    {
        return NULL;

    }

    Node * temp = head->next;
    while(temp!=NULL && temp != head)
{
    temp = temp ->next;    
}

if(temp ==head)
{
    return true;

}
return false;
}

void printL(Node* head)
{
    Node* temp = head;
     
    while(temp != NULL)
    {
        cout<<temp ->data <<"->";

    }
    cout<<"NULL"<<endl;


}


int main()
{

    
    return 0;

}