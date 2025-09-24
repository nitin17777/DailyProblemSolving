#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node*next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int numComponents(Node* head, vector<int>& nums)
{
    unordered_set<int>s(nums.begin(),nums.end());

    int count = 0; 

    bool inComponent = false;

    while(head)
    {
        if(s.count(head->data)) // if current node is in nums
        {
            if(!inComponent)
            {
                count++;
                inComponent = true;
            }
        }

        else
        {
            inComponent = false;
        }
        head = head ->next;
    }
    return count;
}

int main()
{
    Node* head = new Node(0);
    head ->next = new Node(1);
    head ->next->next = new Node(2);
    head ->next->next->next = new Node(3);

    vector<int>nums = {0,1,3};

    cout<<numComponents(head,nums)<<endl;
}