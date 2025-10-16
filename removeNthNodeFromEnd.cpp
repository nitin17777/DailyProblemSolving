#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeNthFromEnd(Node *head, int n)
{

    // count the number of nodes first
    int count = 0;
    Node *temp = head;

    while (temp)
    {
        count++;
        temp = temp->next;
    }

    // deleting the head
    if (n == count)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int steps = count - n - 1;
    Node *prev = head;
    while (steps--)
    {
        prev = prev->next;
    }

    /// reached the previous node
    Node *delNode = prev->next;
    prev->next = prev->next->next;
    delete delNode;

    return head;
}

void print(Node *head)
{

    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *ans = removeNthFromEnd(head, 2);

    print(ans);

    return 0;
}