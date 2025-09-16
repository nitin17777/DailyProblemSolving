#include<iostream>
using namespace std;

class Node
{
    public: 
    Node * next;
    int data;

    Node(int data)
    {
        this ->data = data;
        this ->next = NULL;
    }
};


Node * merge(Node * left , Node * right)
{
    if(!left)return right;
    if(!right)return left;

    Node*result = NULL;


    if(left ->data <= right ->data)
    {
        result = left;
        result->next = merge(left->next,right);
    }

    else
    {
        result = right;
        result ->next = merge(left ,right->next);

    }
    return result;
}


    Node* getMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head ->next;

        while(fast && fast->next)
        {
            slow =slow->next;
            fast = fast->next->next;
        }
        return slow; //And this position would be the mid of the given linked list
    }

    Node* sortList(Node * head)
    {
        if(!head || !head->next)
        return head;

        Node * mid = getMid(head);
        Node *left = head;
        Node* right = mid->next;
        mid->next = NULL; // to split the list into two parts (IMORTANT)

        left = sortList(left);
        right = sortList(right);

        return merge(left,right);

    }

void printList(Node* head)
{
    while(head)
    {
        cout<<head ->data<<" ";
        head = head->next;
    }
   cout<<endl;
}

int main()
{

    Node * head =new Node(4);
    head ->next = new Node(2);
    head ->next->next = new Node(1);
    head ->next ->next ->next = new Node(3);


    cout<<"Before Sorting: ";
    printList(head);

    
    Node * sorted = sortList(head);

    cout<<"After Sorting: ";
    printList(sorted);
    
    return 0;
}