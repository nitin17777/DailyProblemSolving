#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define int long long

#define pb push_back
#define all(a) a.begin(), a.end()

int countMaxOrSubsets(vector<int>& nums)
{

    //we have to find the max possible bitwise OR of a subset of nums and return the number of different non empty subsets with max bitwise or

    //this required subarray can be found out by deleting elements from the given array

    //firstly find the max bitwise or and then find the number of subarrays consisting of this max bitwise and return 

    //total non empty sets = 2^n -1
    //now find all the OR for these subsets
    //And find out the max OR and then calculate how many of these subsets have this max OR

    

    


}





int main()
{
    vector<int>nums = {3,1};

    int ans=  countMaxOrSubsets(nums);

    cout<<ans<<endl;

    return 0;

}


