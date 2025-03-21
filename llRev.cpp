#include<iostream>
#include<map>
using namespace std;

class Node
{
    public:

    int data:
    Node* next;

    //constructor
    this->data = data;
    this->next = NULL;

}

//destructor

~Node()
{
    int value = this->data;

    if(this->next !=NULL)
    {
        delete next;
        this->next=NULL;

    }

    cout<<"Memory is free for node with data."<<value<<endl;

};

void insertAtHead(Node* &head,int d)
{
    Node* temp = new Node(d); //new node with name temp is created with value d

    temp->next = head; // now temp will point to the head( temp ->head)
    head = temp;//and now head value is assigned to temp

}


void insertAtTail(Node* & tail ,int d)
{
    Node * temp = new Node(d);  //created a new node temp with vaulue d
    tail ->next = temp; // tail's next will point to temp now
    tail = temmp; 

}


void print(Node* head)
{
    if(head == NULL)
    {
        cout<<"List is empty."<<endl;
        return ;  // exits theh function immediately
    }

    Node* temp = head; //created a new node temp with vaulue d

    while(temp!=NULL)
    {
        
    cout<<temp->data<<" ";
    temp = temp ->next;
    }
    cout<<endl;
}

void insertAtPosition(Node* & tail,Node* head,int position,int d)

{
    //insert at start
    if( position == 1)
    {
        insertAtHead(head,d);
        return;
    }


    Node* temp = head;
    int cnt =1;


    while(cnt < position-1)
    {
        temp = temp->next;
        cnt++;

    }

    //inserting at last

    if(temp->next == NULL)
    {
        insertAtTail(tail,d);
        return;

    }

    Node * nodeToInsert = new Node(d);

    nodeToInsert->next = temp ->next;

    temp ->next = nodeToInsert;

}


void deleteNode(int position,Node* head)
{

    //deleting first node

    if( position == 1)
    {
        Node* temp = headl
        head = head ->next;

        temp ->next = NULL;
        delete temp;

    }

    else
    {
        // deleting ant middle or last node

        Node * curr = head;
        Node* prev = NULL;

        int cnt= 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next
            cnt++;

        }

        prev ->next = curr->next;

        curr->next =NULL;
        delete curr;

    }
}

bool isCircularList(Node* head)
{
    if(head ==NULL)
    {
        return true;

    }

    Node* temp = head ->next;
    while(temp != NULL && temp != head)
    {
        temp = temp ->next;

    }
    if(temp == head)
    {
        return true;

    }
    return false;


}


bool detectLoop(Node* head)
{
    if(head== NULL)
    {
        return false;

    }

    map<Node*,bool> visited;


    Node* temp = head;
    while(temp != NULL)
    {
        if(visited[temp] == true)
        {
            cout<<"Present on element "<<temp ->data <<endl;
            return true;

        }

        visited[temp] = true;
        temp =temp ->next;



    }
    return false;
    
}


Node* floydDetection(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* slow = head;
    Node* fast = head;
    
    while(slow!= NULL&& fast != NULL)
    {
        fast = fast ->next;
        if(fast != NULL)
        {
            fast = fast ->next;
        }
        slow = slow->next;

        if(fast == slow )
        {
            cout<<"Present at "<<slow->data<<endl;
            return slow;


        }
    }
    return NULL;
    
}