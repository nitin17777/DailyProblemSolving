#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*Approach 1 : Simply sort the give arry and return the required index element


Approach 2: Make a heap with first k elements 
And for the remaining elements, check whether if the element is smaller than top of priority queue and if it is smaller, simply pop the top and push that element ,do it until all the elements are used and at last we will have a pq of k elements and it's top would be our answer

*/





int kthSmallest(vector<int>arr, int k)
{
    //max heap
    priority_queue<int>pq;

    //step 1 : 
    for(int i = 0; i<k ; i++)
    {
        pq.push(arr[i]);
    }

    //step2 :
    for(int i = k; i<arr.size(); i++)
    {
        if(arr[i] < pq.top())
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
    vector<int>arr = {2,3,4,5};
    int k = 2;

    int ans = kthSmallest(arr,k);

    cout<<ans<<endl;

    return 0;

}