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

Node* middleNode(Node* head) {


    Node* slow = head;
    Node* fast = head;

    while(fast!= NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

   return slow;
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node* ans = middleNode(head);

    while(ans)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;

    return 0;
}