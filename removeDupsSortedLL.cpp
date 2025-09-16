#include<iostream>
#include<vector>

using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this ->next = NULL;
    }
};


Node* deleteDuplicates(Node* root)
{
    //if root ->next = root->root ->next = root->next ->next
    //root->next ->next = NULL
    Node* curr = root;

    while(curr != NULL && curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            Node* temp = curr->next;
            curr->next = curr ->next->next;

            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return root;
}

int main()
{

    Node* root = new Node(1);
    root->next = new Node(1);
    root->next ->next = new Node(2);
    root->next ->next->next = new Node(3);

    Node*ans = deleteDuplicates(root);

    while(ans != NULL)
    {
        cout<< ans->data <<" ";
        ans = ans->next;
    }

    cout<<endl;

    return 0;
    
}
