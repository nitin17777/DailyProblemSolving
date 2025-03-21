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


Node* findMid(Node* head)
{

    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast -> next !=NULL)
    {
        slow = slow ->next;
        fast = fast ->next->next;

    }
    return slow;
}


Node* merge( Node* left ,Node* right)
{
    if(left == NULL)
    {
        return right;

    }
    if(right == NULL)
    {
        return left;
        
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge 2 sorted linked list
    while(left != NULL && right != NULL)
    {
        if( left ->data < right->data)
        {
            temp ->next = left;

            temp = left;
            left = left ->next;
        }

        else
        {
            temp ->next = right;
            temp = right;
            right = right ->next;

        }

    }
    while( left!= NULL)
    {
        temp ->next = left;

        temp = left;
        left = left ->next;
        

    }
    while(right !=NULL)
    {
        
        temp ->next = right;

        temp = right;
        right = right ->next;
    }
    return ans->next;

}

Node* mergeSort(Node* head)
{
    //base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    //break linked list into two halves after finding mid
    Node* mid= findMid(head);
    Node* left = head;
    Node* right = mid ->next;

    mid ->next = NULL;

    //recurssive calll to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    Node* result = merge(left,right);

    return result;    
}

void insertAtTail(Node* & head , int val)
{
    Node* newNode = new Node( val);
    if( head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while( temp ->next !=NULL)
    {
        temp = temp ->next;
        
    }
    temp->next = newNode;
}

void printList(Node* head)
{
    while( head!= NULL)
    {
        cout<<head->data <<" ->";
        head = head->next;

    }
    cout<<"NULL"<<endl;

}

int main()
{
    Node* head =  NULL;
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,9);
    insertAtTail(head,3);
    insertAtTail(head,6);

    cout<<"Original List: ";
    printList(head);

    head = mergeSort( head);

    cout<<"Sorted List: ";
    printList(head);

    return 0;
}