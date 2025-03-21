#include<bits/stdc++.h>
using namespace std;


// we have to find the first negative in the given k size window of array 

vector<long long> findNegative(long long int arr[], long long int N, long long int k)
{
    deque<long long int> dq;
    vector<long long> ans;

    // processing first window of k size
    for(int i = 0; i<k; i++)
    {
        if(arr[i] < 0)
        {
            dq.push_back(i); // if element is negative, store it in dq 
        }
    }

    //storing answer of 1st k sized window
    if(dq.size() > 0)
    {
        ans.push_back(arr[dq.front()]);
    }

    else
    {
        ans.push_back(0);
    }

    //sliding window processing window for remaining window
    for(int i = k; i < N; i++)
    {
        if((!dq.empty()) && i - dq.front() >= k )
        {
            dq.pop_front();
        }
        if(arr[i] < 0 )
        {
            dq.push_back(i);

        }

        if(dq.size() > 0)
        {
            ans.push_back(arr[dq.front()]);
        }

        else
        {
            ans.push_back(0);

        }
    }
    return ans;

}

int main()
{



    return 0;

}