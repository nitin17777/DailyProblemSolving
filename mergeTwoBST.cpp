#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* right;
    Node* left;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root,vector<int>& in)
{
    if(root == NULL)
    return;

    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}


vector<int>mergeArrays(vector<int>&a,vector<int>&b)
{
    vector<int>ans(a.size() + b.size());

    int i = 0,j =0,k= 0;


    while(i<a.size() && j<b.size())
    {
        if(a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    while(i < a.size())
    {
        ans[k++] = a[i++];
    }
    while(j < b.size())
    {
        ans[k++] = b[j++];
    }
    return ans;
    
}

Node* inorderToBST(int s, int e, vector<int> & in)
{
    //base case
    if(s>e)
    return NULL;

    int mid = (s+e)/2;

    Node * root = new Node(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1, e,in);

    return root;
}

void convertToSortedDLL(Node* root,Node* & head)
{
    //base case
    if( root == NULL)
    return;

    convertToSortedDLL(root->right,head);

    root->right = head; 

    if(head != NULL)

    head ->left = root;
    head = root;

    convertToSortedDLL(root->left,head);
}

Node* mergeLL(Node* head1,Node* head2)
{
    Node * head = NULL;
    Node * tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        
    if(head1->data < head2->data)
    {
        if(head == NULL)
        {
        head = head1;
        tail = head1;
        head1 = head1->right;
        }

        else
        {
            tail ->right = head1;
            head1->left = tail;
            tail = head1;
            head1=  head1->right;
        }
    }

    else
    {
        if(head == NULL)
        {
        head = head2;
        tail = head2;
        head2 = head2->right;
        }
    
    else
    {
        tail ->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head->right; 
    }
    }
}

while(head1 != NULL)
{
    tail ->right= head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
}

while(head2!=NULL)
{
    tail ->right = head2;
    head2->left = tail;
    tail = head2;
    head2 = head2->right;
}

}

int countNodes(Node* head)
{
    int cnt = 0;
    Node * temp = head;

    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}


Node* sortedLLToBST(Node*& head,int n)
{
    if(n <= 0 || head == NULL)
    return NULL;

    Node* left = sortedLLToBST(head,n/2);

    Node* root = head;

    root->left = left;

    head = head-> right;

    root->right = sortedLLToBST(head,n - n/2 -1);

    return root;

}




Node * mergeBST(Node* root1, Node* root2)
{
/*


    //Step 1: Store inorder 
    vector<int>bst1,bst2;

    inorder(root1,bst1);
    inorder(root2,bst2);

    //step 2 : Merge both sorted arrays
    vector<int>mergedArray = mergeArrays(bst1,bst2);

    //step 3 : use merged inorder array to build BST
    return inorderToBST(0, mergedArray.size()- 1, mergedArray);

    */

    // convert BST into sorted DLL in place
    Node * head1 = NULL;
    convertToSortedDLL(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    convertToSortedDLL(root2,head2);
    head2 ->left = NULL;

    //Merge sorted LL
    Node* head = mergeLL(head1, head2);

    //step3 : Convert SLL into BST
    return sortedLLToBST(head,countNodes(head));

}

int main()
{

    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    // Second BST
    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* mergedRoot = mergeBST(root1,root2);
    

    vector<int>result;

    //printing inorder traversal of merged BST
    inorder(mergedRoot, result);

    cout<<"InOrder Traversal: ";
    for(int val : result)
    {
        cout<<val<<" ";

    }
    cout<<endl;

    return 0;
}