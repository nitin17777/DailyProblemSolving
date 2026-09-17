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


Node* getMid(Node* head)
{
    Node* fast = head->next;
    Node* slow = head;

    while(fast!= NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


Node* merge(Node* left,Node* right)
{
    if(!left)return right;
    if(!right)return left;

    Node* result = NULL;

    if(left->val <= right->val)
    {
        result = left;
        result->next = merge(left->next,right);
    }

    else
    {
        result = right;
        result->next = merge(left,right->next);
    }

    return result;
}

Node* sortList(Node* head)
{

    if(!head || !head->next)return head;

    Node* mid = getMid(head);

    Node* right = mid->next;
    Node* left = head;

    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);

    return merge(left, right);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    
    }

    return 0;
}