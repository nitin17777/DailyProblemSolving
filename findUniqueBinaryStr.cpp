#include<bits/stdc++.h>
using namespace std;

string findDifferentBinaryString(vector<string>& nums)
{
    int n = nums.size();

    //Return any string which is not part of given nums string
    string ans = "";

    //Algo: Flip ith bit of ith string 

    for(int i=0;i<n;i++)
    {
        if(nums[i][i]=='1')ans+='0';

        else ans+='1';
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>nums = {"01","10"};
    cout<<findDifferentBinaryString(nums)<<endl;

    return 0;
}