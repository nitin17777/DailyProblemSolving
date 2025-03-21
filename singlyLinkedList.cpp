#include<iostream>
using namespace std;

class Node //we made a class named node first
{
    public: //type of this class is public
    int data; //initiallising data
    Node* next;   //declares a pointer named next of type Node which means next can store the address of another node

//name of the constructor is Node and int data is the type of data that can be given as input
    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node()
    {
        int value = this ->data ;

        if(this -> next != NULL)
        {
            delete next ;

            this->next = NULL;

        }

        cout<<"Memory is free for node with data "<<value<<endl;

    }


};

void insertAtHead(Node* &head,int d)
{
    //creating a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
 
}

void insertAtTail(Node * &tail,int d)
{
    Node * temp = new Node(d);  // created new node with some value d
    tail -> next = temp ; //Linking current tail node to new node
    tail = tail ->next; // updating tail to new node
}

void print(Node* & head)
{

    Node*temp = head;

    while(temp != NULL)
    {
        cout<<temp->data << " ";
        temp = temp -> next;

    }
    cout<<endl;
}

void insertAtPosition(Node* &head ,Node* &tail, int position,int d)
{
    if(position == 1)
    {
        insertAtHead(head,d);
        return;
    }
    Node*temp = head;

    int cnt = 1;

    while(cnt < position - 1)
    {
        temp = temp ->next;
        cnt++;
    }

    if(temp -> next == NULL)
    {
        insertAtTail(tail,d);
        return;
    }

    //creating a node for d

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp ->next;

    temp -> next = nodeToInsert ;

}

void deleteNode(int position , Node*&head)
{

    //deleting first/start node

    if(position == 1)
    {

        Node *temp = head ;
        head = head ->next;

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

        prev -> next = curr ->next;

        curr ->next = NULL;
        delete curr;
    }


}

//recursive way
void reverse(Node* &head,Node*curr,Node*prev)
{

    //base case
    if(curr == NULL)
    {
        head = prev;
        return ;

    }

    Node* forward = curr ->next;

    reverse(head,forward,curr);
    curr->next = prev;

}

Node * reverseNode(Node * head)
{

    //
    Node * curr = head;
    Node * prev = NULL;
    reverse(head,curr,prev);
    return head;
        //recurive way

    /*

    if( head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node * prev = NULL;
    Node * curr = head;
    Node* forward = NULL;


    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    */


}


int getLength(Node* head)
{
    int len = 0;
    while(head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

Node *findMid(Node * head)
{
    int len = getLength(head);
    int ans = (len/2);
    

    Node* temp = head;

    int cnt = 0;
    while(cnt<ans)
    {
        temp = temp->next;
        cnt++;


    }

    return temp;

}



int main()
{

    //created a new node
    Node* node1 = new Node(5);
    //cout<<node1->data<<endl;
   // cout<<node1->next<<endl;


    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,15);
    print(head);


    insertAtPosition(head,tail,1,33);
    print(head);


    cout<<"Head-"<<head -> data <<endl;
    cout<<"Tail-"<<tail -> data <<endl;

    //deleteNode(4,head);

    head = reverseNode(head);
    print(head);

    Node * mid = findMid(head);

    cout<<"Mid is "<<mid->data<<endl;


    


    return 0;

}