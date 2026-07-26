#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumProduct(vector<int>& nums)
{
    sort(nums.begin(),nums.end());
    int n = nums.size();

    int prod1 = nums[0]*nums[1]*nums[n-1];
    int prod2 = nums[n-1]*nums[n-2]*nums[n-3];

    return max(prod1,prod2);
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<int>a = {1,2,3};
    cout<<maximumProduct(a)<<endl;

    return 0;
}