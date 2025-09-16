#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int kthLargest(vector<int>arr , int k)
{
    //min heap
    priority_queue<int,vector<int>,greater<int>> pq;

    //vector<int> -> container to store elements 
    //greater<int>> pq; -> comparator for min heap*/


    for(int i = 0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i< arr.size();i++)
    {
        if(arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}


int main()
{
    vector<int>arr = {3,2,1,5,6,4};
    int k = 2;

    cout<<kthLargest(arr,k)<<endl;



    return 0;

}