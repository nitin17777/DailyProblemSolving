#include<iostream>
#include<map>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //constructor

    Node(int d )
    {
        this ->data = d;
        this ->next = NULL;
        
    }

    //destructor
    ~Node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            next  = NULL;

        }

        cout<<"Memory is free for node with data "<< value<<endl;

    }
};

void insertNode(Node* &tail ,int element,int d)
{
    //assuming that the element is present in the list 

    //empty list 
    if(tail == NULL)
    {
        Node*newNode = new Node(d);
        tail = newNode;
        newNode ->next = newNode;
    }
    else
    {
        //non empty list and we are assuming that element is present in the list


        Node *curr = tail;
        while(curr->data != element)
        {
            curr = curr->next;

        }
        Node*temp = new Node(d);
        temp ->next = curr->next;
        curr->next = temp;
        
    }
}

void printN(Node* tail)
{
    Node * temp = tail;

    if(tail == NULL)
    {
        cout<<"List is Empty"<<endl;
    }

    do
    {
        cout<<tail->data <<" ";
        tail = tail ->next;
    }

    while(tail != temp);
    cout<<endl;
     
   /* while(tail ->next != temp)
    {
        cout<<tail->data<<" ";
        tail = tail ->nex;
    }

    cout<<" ";
    */

}


void deleteNode(Node* &tail,int value)
{
    if(tail == NULL)
    {
        cout<<"List is empty, please check again."<<endl;
        return;
    }
    else
    {
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;

        }

        prev ->next = curr->next;

        //1 Node Linked List
        if(curr == prev)
        {
            tail = NULL;

        }

        //>=2 Node Linked List
        if(tail == curr)
        {
            tail = prev;

        }

        curr->next = NULL;
        delete curr;

    }
}


bool detect(Node* head) // to detect the loop we just need to check whether if any block appears twice or not
{
    if(head == NULL)
    {
        return false;
    }


        map<Node*, bool>visited;

        Node* temp = head; 

        while(temp != NULL)
        {

            if(visited[temp] == true)
            {
                return true;
            }
            visited[temp] = true;
            temp = temp ->next;


        }
        return false;

    
}

Node * floydDetectLoop(Node* head)
{
    if( head == NULL)
    {
        return NULL;
    }
        Node * slow = head;
        Node* fast = head;

        while( slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if( fast != NULL)
            {
                fast = fast->next;

            }
            slow = slow->next;

            if(slow == fast)
            {
                cout<<"Present at "<<slow->data<<endl;

                return slow;


            }
        }
        return NULL;


    }


Node* getStartingNode(Node* head)
{
    if( head== NULL)
    {
        return NULL;

    }

    Node* intersection = floydDetectLoop(head);
    Node* slow= head;

    while( slow != intersection)
    {
        slow = slow -> next;
        intersection =  intersection-> next;
    }
    return slow;
 
}

void removeLoop(Node* head)
{
    if( head == NULL)
    {
        return;

    }

    Node* startOfLoop = getStartingNode(head);

    Node* temp = startOfLoop;
    while( temp ->next != startOfLoop)
    {
        temp=temp->next;

    }
    
    temp ->next = NULL;
    
}

Node * uniqueSorted(Node* head)
{
    if( head != NULL)
    {
        return NULL;

    }

    Node* curr = head;

    while(curr !=NULL)
    {
        if((curr ->next != NULL) && curr->data == curr->next-> data)
        {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = next_next;
        }
        else
        {
            curr = curr->next;
        }

    }
    return head;
    
}

int main()
{
    Node * tail = NULL;
    Node * head = NULL;



    insertNode(tail,5,3);
    printN(tail);

    insertNode(tail,3,5);
    printN(tail);

    insertNode(tail,5,8);
    printN(tail);

    insertNode(tail,8,11);
    printN(tail);

    insertNode(tail,11,121);
    printN(tail);



   // deleteNode(tail,8);
   // printN(tail);

   if(floydDetectLoop(head) != NULL)
   {
    cout<<"Cycle is presnt. "<<endl;

   }

   else
   {
    cout<<"Cycle is not present. "<<endl;

   }

    return 0;

}