#include<iostream>
using namespace std;
 //flatten the code by recurssion .....
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
};