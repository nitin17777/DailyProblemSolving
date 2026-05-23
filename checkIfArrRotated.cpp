#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<int>& nums)
{
    int n = nums.size();


    // 3 4 5 1 2 3 4 5 1 2

    //Connected the array twice, now for each position till n-1 check if forward n elements are sorted or not
    /*

    Check if arr was initially sorted and then rotated few positions else return false

    
    */

    int cnt =0;

    for(int i = 0;i<n;i++)
    {
        if(nums[i] > nums[(i+1)%n])cnt++;
    }
    return cnt <= 1;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {3,4,5,1,2};
    cout<<(check(nums)?"True" :"False")<<endl;
    
    return 0;
}