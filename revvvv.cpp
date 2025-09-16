#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int d)
    {

        
    }
};

if(head == NULL)
{
    return NULL;
}



int main()
{

    Node* head = new Node(1);
    head ->next = 2;
    head ->next->next = 3;
    head ->next->next->next = 4;
    head ->next->next->next->next = 5;

    int k = 3;

    Node* ans = revK(head,k);

    




    return 0;

}