#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

//   BRUTE FORCE
Node* rotateRight1(Node* head, int k)
{
    // Rotate the list to the right by k places


    if(!head || !head->next)return head;

    int n = 1;
    Node* tail = head;
    while(tail->next)
    {
        n++;
        tail = tail->next;
    }

    k = k%n;
    if(k == 0)return head;


    while(k--)
    {
        Node* temp = head;

        while(temp->next->next != NULL)temp = temp->next;

        Node* last = temp->next;

        temp->next = NULL;
        last->next = head;

        head = last;
    }
    return head;
}




Node* rotateRight(Node* head, int k)
{
    // Rotate the list to the right by k places


    if(!head || !head->next)return head;

    int n = 1;
    Node* tail = head;
    while(tail->next)
    {
        n++;
        tail = tail->next;
    }

    k = k%n;
    if(k == 0)return head;



    //Making the linked list circular
    tail->next = head;

    int steps = n-k;
    
    Node* newTail = head;

    for(int i = 1;i<steps;i++)newTail = newTail->next;

    // Break the cycle
    Node* newHead =  newTail->next;
    newTail->next = NULL;

    return newHead;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);

    Node* ans =rotateRight(root,2);

    while(ans)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }

    cout<<endl;

    return 0;
}