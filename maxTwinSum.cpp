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

int pairSum(Node* head)
{

    //Return the max twin sum of ll

    Node* slow = head;
    Node* fast = head;


    // Find middle
    while(fast && fast->next)
    {
        slow =slow ->next;
        fast = fast->next->next;
    }

    //Reversing second half
    Node* prev = NULL;

    while(slow)
    {
        Node* nxt = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nxt;
    }

    int ans = 0;

    //Calculating max twin sum

    while(prev)
    {
        ans = max(ans,head->data + prev->data);

        head = head->next;
        prev = prev->next;
    }
    return ans;
}



      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node*head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout<<pairSum(head)<<'\n';

    return 0;
}