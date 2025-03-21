#include<iostream>
using namespace std;


class  Node
{

    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL; //initially prev is NULL
        this -> next = NULL; //initially next is NULL

    }

    ~Node()
    {
        int val = this->data;
        if(next != NULL)
        {
            delete next;
            next = NULL;

        }
        cout<<"Memory free for node with data "<<val;

    }
};


void print(Node* head)
{

    Node*temp = head; // new pointer temp of type Node is created and is assigned the address of head.

    while(temp != NULL) // when temp is not null

    {
        cout<<temp ->data<<" "; // prints the value of data in current node

        temp = temp->next; 
    }
    cout<<endl;
}

int getLength(Node * head )
{
    int len = 0;

    Node* temp = head; // a new pointer temp of type node is created and is assigned the value of head


    while(temp != NULL)
    {
        len++;
        temp = temp ->next; //updates temp to point to the next node
    }
    return len;
}

void insertAtHead(Node* &tail ,Node*&head ,int d)
{
     if(tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    Node * temp = new Node(d); //we created a new node temp
    temp ->next = head;         // temp ka jo next tha wo head ko point karega
    head->prev = temp;          // aur jo head ka prev tha vo temp ko point karega
    head = temp; //ab  temp jo h wo naya head ban jaega
    }


}

void insertAtTail(Node* &tail ,Node*&head , int  d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
    Node* temp = new Node(d);
    tail->next = temp;  //tail ka next point karega temp ko
    temp ->prev = tail;// temp ka prev point karega tail ko
    tail = temp ;//tail ab change hogi aur temp tail ban jaegi
    }
     
}


void insertAtPosition(Node* &tail,Node*& head,int position, int d)
{
    if(position == 1)
    {
        insertAtHead(tail,head,d);
        return;
    }
    Node*temp = head;
    int cnt =1;

    while(cnt<position-1)
    {
        temp = temp->next;
        cnt++;
        
    }

    //inserting at last position
    if(temp -> next == NULL)
    {
        insertAtTail(tail,head,d);
        return;

    }
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp->next;

    temp -> next->prev = nodeToInsert;
    temp ->next = nodeToInsert;
    nodeToInsert -> prev = temp;

}



void deleteNode(int position,Node*& head)
{

    if(position == 1)
    {
        Node * temp = head;
        temp-> next->prev = NULL;
        head = temp->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle or last node
        Node* curr = head;
        Node * prev = NULL;

        int cnt = 1; 

        while(cnt < position)
        {
            prev = curr ;
            curr = curr -> next;
            cnt++;

        }
        curr ->prev = NULL;
        prev->next = curr ->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    //Node* node1 = new Node(10); //creating 1st node with value of 10


    //Node* head= node1; // new pointer head of type Node is created and is assigned the address of node 1, making head point to node1 and tail pointing to node1 as well

    Node* head= NULL;

    //Node *  tail = node1;
    Node *  tail = NULL;

    print(head);


    insertAtHead(tail,head,11);
    print(head);

    insertAtHead(tail,head,13);
    print(head);

    insertAtHead(tail,head,8);
    print(head);

    insertAtTail(tail,head,25);
    print(head); 

    insertAtPosition(tail,head,2,113);
    print(head);

    insertAtPosition(tail,head,6,124);
    print(head);

    deleteNode(1, head);
    print(head);



    return 0;

}