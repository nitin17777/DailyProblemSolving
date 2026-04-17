#include<bits/stdc++.h>
#define ll long long
using namespace std;


int reverseint(int n)
{
    ll num = n;
    int sign = (num < 0)?-1 : 1;
    num = abs(num);
    
    ll rev = 0;
    
    while(num)
    {
        int digit = num%10;
        rev =  rev* 10 +digit;

        if(rev > INT_MAX)return 0;

        num/=10;
    }
    return sign * (int)rev;
}


int minMirrorPairDistance(vector<int>& nums)
{
    //Storing number with the latest index where it appeared
    unordered_map<int,int>mp;

    int mini = INT_MAX;

    for(int i = 0;i<nums.size();i++)
    {

        //instead of reversing current num, check if current exists as reverse of previous

        if(mp.find(nums[i]) != mp.end())
        {
            mini = min(mini,i-mp[nums[i]]);
        }

        int r = reverseint(nums[i]);
        mp[r] = i;
    }
    return mini == INT_MAX?-1:mini;
}

/*

        BRUTE FORCE APPROACH






int minMirrorPairDistance(vector<int>& nums)
{
    int n = nums.size();

    //Mirror pair : reverse(nums[i]) == nums[j]

    //Return the min diff bw indices of any mirror pair

    // if no mirror pair is there, return -1

    int mini = INT_MAX;

    for(int i = 0;i<n;i++)
    {
        int r = reverseint(nums[i]);

        for(int j = i+1;j<n;j++)
        {
            if(r == nums[j])
            {
                mini = min(mini,abs(i-j));
            }
        }
    }
    return mini==INT_MAX?-1:mini;
}

*/

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a= {120,21};

    cout<<minMirrorPairDistance(a)<<endl;
    
    return 0;
}