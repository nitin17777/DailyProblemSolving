#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minOperations(vector<int>& nums)
{
    int n = nums.size();

    //We can reverse the entire array  or rotate left by one 

    //Determine min number of ops to sort the array else return -1


    //Both of it's adjacent elements must be adjacent to it somehow surely else -1

    //finding index of 0 in the array
    int z = find(nums.begin(),nums.end(),0)-nums.begin();

    bool forward = true,backward = true;

    for(int i = 0;i<n;i++)
    {
        if(nums[(z+i)%n] != i)forward = false;

        if(nums[(z-i+n) %n] != i)backward = false;
    }

    int ans = INT_MAX;
    if(forward)
    {
        // Rotate directly, or reverse twice with rotations between.
        ans = min(ans,z);
        ans = min(ans,n-z+2);
    }

    if(backward) 
    {
        // Reverse first, or rotate then reverse.
        ans = min(ans, n - z);
        ans = min(ans, z + 2);
    }
    return ans == INT_MAX ? -1: ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {0,2,1};
   cout<<minOperations(nums)<<'\n';

    return 0;
}