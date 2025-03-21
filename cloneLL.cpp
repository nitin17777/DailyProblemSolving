#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int data;
     Node*next;
     Node* random;
     
     Node(int x)
     {
        data = x;
        next = NULL;
        random =NULL;

     }
};

class Solution
{    private:
    void insertAtTail(Node*& head, Node* &tail, int d)
    {
        Node* newNode=new Node(d);
        if(head == NULL)
        {
            head= newNode;
            tail = newNode;

        }
        else
        {
            tail->next = newNode;
            tail = newNode;

        }
    }


    public:
    Node *copyList(Node* head)
    {

        //Step 1 -> create a clone list

        Node * cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp =head;

        while(temp != NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode= cloneHead;


        while(originalNode != NULL && cloneNode != NULL)

        {
            Node* next =originalNode->next;
            originalNode->next = cloneNode;
            originalNode= next;

            next= cloneNode ->next;
            cloneNode ->next = originalNode;
            cloneNode= next;
        }


        //step3 : copy random pointer

        temp = head;

        while( temp!=NULL)
        {

            if(temp->next != NULL)
            {
                temp ->next->random = (temp ->random!=NULL) ? temp -> random ->next: NULL;
            }
            temp = temp ->next ->next;
        }


        // Step 4 -> Revert all changes done in step 2
        originalNode= head;
        cloneNode= cloneHead;

        while(originalNode != NULL && cloneNode != NULL)

        {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;


            if(originalNode != NULL)
            {
            cloneNode ->next = originalNode->next;
            }
            cloneNode= cloneNode->next;
        }

        return cloneHead;

    }
};

/*



class Solution
{
private:

void insertAtTail(Node* &head, Node* &tail , int d)
{

    Node* newNode = new Node(d);


    if( head == NULL)
    {
        head = newNode;
        tail= newNode;
        return;

    }
    else
    {
        tail ->next= newNode;
        tail = newNode;  
    }

}

    public:
    Node* copyList(Node* head)
    {

        if(!head)
        return NULL;

        //step1: Create a clone list first

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp = temp ->next;

        }

        //step 2 : Create a map of name oldToNewNode
        unordered_map<Node* , Node* >oldToNewNode;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL )
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode= originalNode->next;

            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;


        while(originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode -> random];
            originalNode = originalNode->next;

        }
        return cloneHead;



    }

};

void printList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<"Data: "<<temp->data;

        if(temp ->random)
        {
            cout<<",Random: " <<temp->random->data;

        }
        else

        {
            cout<<",Random: NULL";

        }
        cout<<endl;
        temp = temp->next;

    }
}



int main()
{

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Connecting the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Assigning random pointers
    head->random = third;   // 1 -> 3
    second->random = head;  // 2 -> 1
    third->random = fourth; // 3 -> 4
    fourth->random = second; // 4 -> 2


    cout << "Original List:\n";
    printList(head);

    // Creating a copy of the list
    Solution sol;
    Node* clonedHead = sol.copyList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);
    return 0;

}

*/

//Approach 2: Without uisng any mapping