#include<bits/stdc++.h>
#define ll long long
using namespace std;

int wavy(int n)
{
    vector<int>nums;
    int t = n;

    int ans = 0;
    while(t>0)
    {
        int rem = t%10;
        nums.push_back(rem);
        t/=10;
    }

    reverse(nums.begin(),nums.end());

    for(int i = 1;i<nums.size()-1;i++)
    {
        if((nums[i] > nums[i-1] && nums[i] > nums[i+1]) || nums[i] < nums[i-1] && nums[i] < nums[i+1])ans++;
    }
    return ans;
}

int totalWaviness(int num1, int num2)
{
    //Return the total number of peaks and valleys in given number range

    int ans = 0;
    for(int i = num1;i<=num2;i++)
    {
        ans += wavy(i);
    }
    return ans;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<totalWaviness(120,130)<<endl;

    return 0;
}