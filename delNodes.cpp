#include <bits/stdc++.h>
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

Node *modifiedList(vector<int> &nums, Node *head)
{
    // delete every presence of elements present in given array from the linked list
    int n = nums.size();

    unordered_set<int> st(nums.begin(), nums.end());

    Node *dummy = new Node(-1);
    dummy->next = head;
    Node *curr = dummy;

    while (curr->next != NULL)
    {
        if (st.count(curr->next->data))
        {
            Node *del = curr->next;
            curr->next = curr->next->next;

            delete del;
        }

        else
        {
            curr = curr->next;
        }
    }
    Node *newHead = dummy->next;
    delete dummy;
    return newHead;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Node *ans = modifiedList(nums, head);

    while (ans)
    {
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}
