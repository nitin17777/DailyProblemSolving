#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *partition(Node *head, int x)
{
    // All the nodes less than x come before nodes greater than or equal to x and not the actual sorting

    Node beforeHead(0), afterHead(0);
    // iterate and if the value is smaller than x , append it to beforeHead else append to afterHead

    Node *before = &beforeHead, *after = &afterHead;

    while (head)
    {
        if (head->data < x)
        {
            before->next = head;
            before = before->next;
        }
        else
        {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;

    before->next = afterHead.next;

    return beforeHead.next;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    Node *ans = partition(head, 3);

    while (ans != NULL)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }

    return 0;
}