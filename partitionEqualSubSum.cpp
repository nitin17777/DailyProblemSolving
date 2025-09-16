#include<bits/stdc++.h>
using namespace std;


bool canPartition(vector<int>&arr)
{
    //we have to return true if we can partition the given array into two subsets such that the sum of elements in both subsets is equall , else return false


    // to calculate the sum of  elements of range
    int total = accumulate(nums.begin(),num.end(),0);
    //(start_iterator, end_iterator, initial_value)

    //we should know that, if the total sum is odd no. , we can't spilt it into two eqaul subsets
    if(total % 2 != 0)
    return false;

    //defining total sum sum for one subet
    int target = total/2;


    //now creating a dp to track which subset sums are possible , and initially , every element is marked false;


    vector<bool>dp(target +1 , false);

    dp[0] =true; // since subset of 0 is always possible , i.e by taking no elements


    for(int num :nums)
    {
        for(int j = target; j>= 0 ; j--)
        {
            dp[j] = dp[j] || dp[j-num];

        }
    }
    return dp[target];
}

int main()
{

    vector<int>arr = {1,5,11,5};

    if(canPartition(arr))
    {
        cout<<"The array can be partitioned."<<endl;
    }

    else
    {
        cout<<"The array cannot be partitioned."<<endl;
    }

    return 0;
}