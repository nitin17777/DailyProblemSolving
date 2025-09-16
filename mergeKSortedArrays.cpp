#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Node
{
    int data;
    Node* right;
    Node* left;

    Node(int data)
    {
        this ->data = data;
        this ->right = NULL;
        this ->left = NULL;
    }
};

class compare
{
    public:
    bool operator() (Node * a, Node* b)
    {
        return a->data > b->data
    }
};

vector<int> mergeKSorted(vector<vector<int>>& kArrays, int k)
{
    priority_queue<Node*, vector<Node*>,compare>minHeap;

    //Step 1 : Insert 1st element h of k arrays
    

    for(int i =0; i < k;i++)
    {
        Node* temp = new Node(arr[i][0], i ,0);
        
    }
}

int main()
{
    return 0;

}