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


void removeLoop(Node *head)
{
    if(head != NULL || head->next == NULL)
    return;

    Node* fast = head;
    Node * slow = head;

    bool hasLoop = false;

    while(fast != NULL && fast ->next != NULL)
    {
        slow = slow->next;
        fast = fast ->next;

        if(slow == fast)
        {
            hasLoop = true;
            break;     
        }
    }

    //And now if the loop exists:
    if(hasLoop)
    {
        slow = head;

        if(slow == fast)
        {
            while(fast ->next != slow)
            {
                fast = fast ->next;
            }
        }

        else

        {
            while(slow ->next != fast ->next)
            {
                slow = slow->next;
                fast = fast ->next;
            }
        }
        fast->next = NULL;
    }
}

int main()
{

    Node * head = new Node()
    return 0;

}