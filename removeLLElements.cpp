#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    Node*next;
    int data;

    Node(int data)
    {
        this ->data = data;
        this->next = NULL;
    }
};


Node* removeElements(Node* head, int val)
{
    //when head node's value matches with the given val
    while(head != NULL && head->data == val)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;

    while(curr != NULL && curr->next != NULL)
    {
        if(curr->next ->data == val)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr ->next;
        }
    }
    return head;

}

Node* makeList(const vector<int>&values)
{
    //when no values are given
    if(values.empty())
    return NULL;


    Node* head = new Node(values[0]);
    Node* current =head;

    for(int i = 1; i <values.size(); i++)
    {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}



Node* printList(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
}

int main()
{

    vector<int>nums = {1,2,6,3,4,5,6};
    Node * head = makeList(nums);

    int val =6;

    head = removeElements(head,val);

    printList(head);

    return 0;
}