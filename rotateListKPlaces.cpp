#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public: 

    Node* next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


Node * rotateRight(Node* head,int k)
{
    //we have to rotate the given linked list by k places in right
    if(head == NULL || head->next == NULL || k== 0)
    return head;

    //counting it's length
    int len = 1;

    Node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }

    k = k % len; // this is for the case where k >length
    //it's like : if len = 5 and k = 7; then moving 7 times == moving 2 times

    if(k == 0)return head;

    //now making the linked list circular

    tail->next = head;

    int stepsToNewTail = len -k; // because, as we start rotating, the last k nodes will become the first k nodes and new tail would be : the element at len-k

    Node * newTail = head;

    for(int i = 1; i <stepsToNewTail; i++)
    {
        newTail = newTail->next;//iterating and assigning our new tail
    }

    Node* newHead= newTail->next;
    newTail->next = NULL;


    return newHead;

}

void print(Node * head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

int main()
{
    Node * head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);





    int k = 2;

    Node* ansHead = rotateRight(head,k);
    

    print(ansHead);



    return 0;
}