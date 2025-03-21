#include<iostream>
using namespace std;



class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
    this->data = data;
    this->next = NULL;
    }

}

void solve(Node<int>* first , Node<int>* second)
{

    if(first->next == NULL)
    {
        first->next = second;
        return first;

    }
    Node* curr1= first;
    Node* next1 = curr1->next;
    Node* curr2= second;
    Node* next2 = curr2 ->next;


    while( next1 !=NULL && curr2!=NULL)
{

    if((curr2->data >= curr1->data) && ( curr2->data <= next1 ->data))
    {
        curr1 ->next = curr2;
        next2 = curr2->next;
        curr2->next = next1;


        //update pointers
        curr1 = curr2;
        curr2 = next2;
    }
    else
    {
        curr1 = next1;
        next1 = next1 ->next;

        if(next1 == NULL)
        {
            curr1 -> next = curr2;
            return first;

        }

    }
}
}

Node<int>* sortTwo(Node<int>* first, Node<int>* second)

{
    if( first == NULL)
    return second;

    if(second == NULL)
    return first;


    if( first->data <=second->data)
    {
        solve (first,second);
    }

    else
    {
        solve(second,first);
    }
    
}

int main()
{



    return 0;

}