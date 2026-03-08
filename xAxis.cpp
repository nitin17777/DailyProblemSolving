#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;

        vector<int>nums = {a,b,c};
        sort(nums.begin(),nums.end());
    
        int median = nums[1];

        int ans = abs(nums[0]-median) + abs(nums[1]-median)+ abs(nums[2]-median);
        
        cout<<ans<<endl;
    }
    return 0;
}