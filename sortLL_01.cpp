#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;

    }
};


void insertAtTail(Node* & tail ,Node* curr)
{
    tail->next = curr;
    tail =curr;

}

Node* sortList(Node* head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL)
    {
        if( temp->data == 0)
        zeroCount++;
        else if(temp->data == 1)
        oneCount++;
        else if(temp->data == 2)
        twoCount++;

        temp = temp->next;


    }
    temp = head;
    while(temp!=NULL)
    {
        if(zeroCount !=0)
        {
            temp->data = 0;
            zeroCount--;


        }
        else if(oneCount !=0)
        {
            temp->data = 1;
            oneCount--;

        }
        else if(twoCount !=0)
        {
            temp->data = 1;
            twoCount--;
            
        }
        temp = temp->next;

    }
    return head;

}


void printL(Node* head)
{
    Node* temp = head;
    while( temp!=NULL)
    {
        cout<<temp->data<<" ";

        temp = temp ->next;
    }
    cout<<endl;
}


int main()
{

    Node* head = new Node(1);
    head ->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node( 0);


    cout<<"Original List : ";
    printL(head);


    head = sortList(head);
    cout<<"Sorted List: ";
    printL(head);


    return 0;

}