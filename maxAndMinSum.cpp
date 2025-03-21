#include<bits/stdc++.h>
using namespace std;

//Sum of min and max of elements of subarrays of size k

int solve(int *arr , int n, int k)
{
    deque<int>maxi(k); // made two queues for max and min element of the subarray


    deque<int>mini(k);

    //Addition of first k size window

    for(int i =0; i<k; i++) // processing first 'k' elements
    {

        // Remove all smaller elements from back for maximum deque
        while(!maxi.empty() && arr[maxi.back()] <= arr[i] )
        {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);

        mini.push_back(i);

    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    for(int i = k; i<n; i++)
    {
        //next window
        while(!maxi.empty() && i - maxi.front() >=k)
        {
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >=k)
        {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i] )
        {
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);

        mini.push_back(i);

    

    // make sure to consider last window
    ans += arr[maxi.front()] + arr[mini.front()];
}

    return ans;
}



int main()
{

    int arr[7] = {2,-5,-1,7,-3,-1,-2};

    cout<<solve(arr,7,3) << endl;

    return 0;

}