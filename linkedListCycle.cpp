#include<iostream>
#include<unordered_set>
using namespace std;

class Node
{
    public:
    
    int data;
    Node* next;

    Node(int data)
    {
        this ->data = data;
        this ->next = NULL;

    }
};



bool hasCycle(Node* head)
{

    if(head == NULL)
    return false;
   
    Node * fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {

    slow = slow->next;
    fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }
    return false;

    }


    //using hashMaps to solve this question
    bool hasCyclee(Node* head)
    {
        unordered_set<Node*>visited; // creating an empty hash set

        while(head != NULL)
        {
            if(visited.find(head) != visited.end())
            {
                return true;
            }

        
        visited.insert(head);
        head = head ->next;
        }
        return false;

    }


int main()
{

    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head->next;

    if(hasCycle(head))
    {
        cout<<"Cycle Detected."<<endl;

    }
    else
    {
        cout<<"No Cycle Detected."<<endl;
    }
    return 0;

}