#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> resultArray(vector<int>& nums)
{
    int n = nums.size();

    vector<int>a,b;

    a.push_back(nums[0]);
    b.push_back(nums[1]);

    int i = 2;
    //last element of arr1 > that of arr2 -> a.push_back(nums[i])  else push in b 

    //Fianl result -> concatenate a and b


    for(int i = 2;i<n;i++)
    {
        if(a.back() > b.back())
        {
            a.push_back(nums[i]);
        }
        else b.push_back(nums[i]);
    }
    for(auto& x:b)a.push_back(x);
    
    return a;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {2,1,3};
    vector<int>ans = resultArray(nums);
    for(auto&x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}