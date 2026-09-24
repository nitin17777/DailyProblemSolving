#include<bits/stdc++.h>
#define ll long long
using namespace std;

int sum(int n)
{
    int ans = 0;

    while(n)
    {
        ans+= (n%10);
        n/=10;
    }
    return ans;
}

int smallestIndex(vector<int>& a)
{
    int n=a.size();

    //sum of digit of nums[i] == i

    for(int i = 0;i<n;i++)
    {
        if(sum(a[i]) == i)return i;
    }
    return -1;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,3,2};
    cout<<smallestIndex(nums)<<endl;

    return 0;
}