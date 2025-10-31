#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *rev(Node *head)
{
    Node *prev = NULL;

    while (head)
    {
        Node *nextNode = head->next;

        head->next = prev;
        prev = head;

        head = nextNode;
    }
    return prev;
}

bool isPal(Node *head)
{
    if (!head || !head->next)
        return true;

    Node *slow = head, *fast = head;

    // To find mid
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reversing second half
    slow = rev(slow);
    Node *secondHalf = slow;
    Node *firstHalf = head;

    while (secondHalf)
    {
        if (firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main()
{
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(2);
    root->next->next->next = new Node(1);

    if (isPal(root))
    {
        cout << "Is Palindrome." << endl;
    }
    else
    {
        cout << "Is not a Palindrome." << endl;
    }

    return 0;
}