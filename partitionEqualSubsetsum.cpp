#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canPartition(vector<int>& a)
{

    int n = a.size();

    //Determine if we can partition subset such that sum of elements in both subsets is equal else return false


    //So now we just need to find a subset whose sum is eqxactly S/2
    //If s is odd -> false immediately

    int total = 0;

    for(auto& x:a)total+=x;

    if(total%2!=0)return false;


    int target = total/2;

    vector<bool>dp(target+1,false);


    //dp[i] = can we make the sum i using numbers i have processed so far

    dp[0] = true;

    for(int num:a)
    {

        //Traverse backwards
        for(int j = target; j>=num; j--)
        {
            dp[j] = dp[j] || dp[j-num];
        }
    }
    return dp[target];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,5,11,5};

    cout<<(canPartition(nums)?"True":"False")<<endl;

    return 0;
}