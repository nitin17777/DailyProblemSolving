#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
    this->data = val;
    this->next = NULL;
    }

};



Node* merge2(Node* list1, Node* list2)
{
    /*

    if(list1 == NULL)
    return list2;

    if(list2 == NULL)
    return list1;

    Node* head = NULL;

    if(list1->data < list2->data)
{
    head = list1;
    list1 = list1->next;
}
else

{
    head = list2;
    list2 = list2->next;
}

Node* tail = head;
while(list1 && list2)
{
    if(list1->data < list2->data)
    {
        tail->next = list1;
        list1 = list1->next;
    }
    else
    {
        tail->next = list2;
        list2 = list2->next;
    }
    tail = tail->next;


}

}
*/

if(list1 == NULL)
return list2;

if(list2 == NULL)
return list1;


if(list1 ->data < list2->data)
{
    list1->next = merge2(list1->next, list2);
    return list1;
}

else
{
    list2->next = merge2(list1,list2->next);
    return list2;
}
}


int main()
{
    Node* a = new Node(1);
    a->next = new Node(3);
    a->next ->next = new Node(6);

    Node* b = new Node(4);
    b->next = new Node(7);
    b->next -> next = new Node(9);

    Node* ans = merge2(a,b);

    while(ans!= NULL)
    {
        cout<<ans->data<<" ";
        ans = ans->next;
    }
cout<<endl;

return 0;

}

