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
        this ->next = NULL;

    }

};

class Solution
{
    private:
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr!=NULL)
        {
            next =  curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }
        return prev;
    }

    void insertAtTail(struct Node* &head , struct Node* &tail,int val )
    {
        Node* temp = new Node(val);

        if( head == NULL)
        {
            head = temp;
            tail = temp;
            return;


        }
        else
        {
            tail ->next = temp;
            tail = temp ;
        }
    }

        struct Node* add(struct Node* first ,struct Node* second)
        {
            int carry = 0;

            Node* ansHead = NULL;
            Node* ansTail = NULL;
            
            while(first != NULL ||  second != NULL || carry !=0)
            {
                int val1 = 0;
                if(first!=NULL)
                {
                    val1 = first ->data;

                }

                int val2 = 0;
                if(second!=NULL)
                {
                    val2 = second ->data;

                }

                int sum = carry + val1 + val2;
                int digit= sum% 10;

                insertAtTail(ansHead,ansTail,digit);

                carry = sum/10;

                if(first != NULL)
                {
                first = first->next;
                }
                if(second!= NULL)
                {
                second = second->next;
                }
                
            }
            return ansHead;

        }
    public:
    struct Node* addTwo(struct Node* first, struct Node* second)
    {
        //reverse first
        first = reverse(first);
        second = reverse(second);

        //add 2 LL
        Node* ans= add(first,second);

        ans = reverse(ans);

        return ans;
    }
};

int main()
{
    Node* first = new Node(2);
    first->next = new Node(4);
    first->next->next = new Node(3); // Represents number 342

    Node* second = new Node(5);
    second->next = new Node(6);
    second->next->next = new Node(4); // Represents number 465

Solution obj;

    Node* an = obj.addTwo(first,second);

    Node* temp= an;
    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
     cout<<endl;
    return 0;

}