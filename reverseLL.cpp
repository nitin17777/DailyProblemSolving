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


Node * reverseLL(Node * head)
{
    if(head == NULL || head ->next == NULL)
    return head;

    Node * newHead = reverseLL(head ->next);
    head ->next->next = head;
    head ->next = NULL;

    return newHead;
}

void printNode(Node * head)
{
    if(head == NULL)
    {
        return;
    }

    while(head)
    {
        cout<<head->data<<" ";
        head = head ->next;
    }
    cout<<endl;

}

int main()
{
    Node* head = new Node(1);
    head ->next = new Node(2);
    head ->next->next = new Node(3);


    cout<<"Given Linked List: ";
    printNode(head);


    Node* neww =  reverseLL(head);
    cout<<"Reversed Linked List: ";
    printNode(neww);



    return 0;

}