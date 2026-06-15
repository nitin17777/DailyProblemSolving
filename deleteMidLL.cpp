#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
    int vak;
    Node* next;

    Node(int val) {
        val = val;
        next = NULL;
    }
};

Node* deleteMiddle(Node* head)
{


    if(!head || !head->next)return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast&& fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    //Now slow is at the mide node

    prev->next = slow->next;
    delete slow;
    
    return head;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}