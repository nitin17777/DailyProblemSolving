#include<iostream>
#include<vector>
using namespace std;


class Node
{
    public:
    int data;
    Node* next;

    Node(int data){

   
    this->data = data;
    this->next = NULL;
    }
};



/*

Approach 1 -> Converting given linked list to array and then checking for palindrome


bool checkPal(vector<int>arr)
{
    int n = arr.size();
    int s= 0;
    int e = n-1;

    while(s<=e)
    {
        if(arr[s] != arr[e])
        {
            return 0;

        }
        s++;
        e--;

    }
    return 1;

}

bool isPal(Node* head)
{
    vector<int>arr;

    Node* temp = head;
    while(temp != NULL)
    {
        arr.push_back(temp ->data);
        temp = temp ->next;

    }

    return checkPal(arr);


}
    */

class Solution
{
    private:
    Node* getMid(Node* head)

    {
        Node* slow = head;
        Node* fast = head->next;


        while(fast!= NULL && fast->next != NULL)
        {

            fast = fast->next->next;
            slow = slow->next;
    }

    return slow;

}

Node* reverse(Node* head)
{
    Node * curr =head;
    Node * prev = NULL;
    Node* next = NULL;

    while( curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;

}

public:
 bool isPal(Node* head)
 {
    if(head ->next == NULL)
    {
        return true;


    }
    //step 1 -> Find Middle
    Node* middle = getMid(head);

    //Step 2-> reverse list after middle
    Node* temp = middle->next;
    middle ->next = reverse(temp);


    //step 3 -> Compare both halves
    Node * head1 = head;
    Node* head2 = middle ->next;


    while( head2!=NULL)
    {
        if(head1->data != head2 -> data)
        {
            return false;

        }

        head1 = head1 ->next;
        head2 = head2->next;

    }



//step 4-> repeat step 2; optional
temp = middle->next;
middle ->next = reverse( temp);

return true;

 }


};



/*int main()
{

    Node* head = new Node(1);
    head ->next = new Node(2);
    head ->next->next = new Node(5);


    if(isPal(head))
    {
        cout<<"The linked list is Palindrome.";

    }
    else
    {
        cout<<"The linked list is not a Palindrome.";

    }
    return 0;

}
    */