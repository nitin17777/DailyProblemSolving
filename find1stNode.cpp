#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;

    Node(int data)
    {
        this ->data = data;
        this ->next = NULL;
    }
};

Node * findNode(Node * head)
{
    if(head == NULL || head ->next == NULL)
    return;

    Node * fast = head;
    Node * slow = head;

    bool loop = false;

    while(fast != NULL && fast ->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }


    return fast->data;



}

int main()
{

    Node * head = new Node(1);
    head ->next = new Node(3);
    head ->next ->next = new Node(2);
    head ->next ->next->next = new Node(4);
    head ->next ->next->next ->next = new Node(5);

    Node * ans = findNode(head);

    cout<<ans<<endl;

   return 0;
}

