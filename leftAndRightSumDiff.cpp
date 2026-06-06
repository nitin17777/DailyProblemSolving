#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> leftRightDifference(vector<int>& nums)
{
    int n = nums.size();
    vector<int>left(n),right(n);

    left[0] = nums[0];
    for(int i = 1;i<n;i++)
    {
        left[i] = left[i-1] + nums[i];
    }

    right[n-1] = nums[n-1];

    for(int i=n-2;i>=0;i--)
    {
        right[i] = right[i+1] + nums[i];
    }

    for(int i = 0;i<n;i++)
    {
        nums[i] = abs(left[i]-right[i]);
    }
    return nums;       
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int>a={10,4,8,3};
    vector<int>ans = leftRightDifference(a);
    for(auto &x:ans)cout<<x<<" ";

    cout<<endl;
    

    return 0;
}