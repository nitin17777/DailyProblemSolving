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
};

//we are given two linked lists,we have to reverse both and add and then again reverse the anwer and return th answer

Node* add2Numbers(Node* l1 , Node * l2)
{
    Node* dummy = new Node(0);
    Node* curr = dummy;;
    int carry = 0;

    while(l1 || l2 || carry)
    {
        int sum = carry;

        if(l1)
        {
            sum += l1 ->data;
            l1 = l1->next;
        }

        if(l2)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum /10;
        curr ->next = new Node(sum % 10);
        curr = curr->next;
    }
    return dummy->next;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

     // Example: l1 = [2, 4, 3], l2 = [5, 6, 4]
     Node* l1 = new Node(2);
     l1->next = new Node(4);
     l1->next->next = new Node(3);
 
     Node* l2 = new Node(5);
     l2->next = new Node(6);
     l2->next->next = new Node(4);
 
     Node* result = add2Numbers(l1, l2);
 
     printList(result);  // Output: 7 0 8

    return 0;

}