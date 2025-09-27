#include <iostream>
using namespace std;

Node *partition(Node *head, int x)
{
    // All the nodes less than x come before nodes greater than or equal to x
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(2);

    return 0;
}