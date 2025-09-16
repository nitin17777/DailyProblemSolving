#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define int long long

#define pb push_back
#define all(a) a.begin(), a.end()


    string largestNumber(vector<int>& nums)
    {
        //push all numbers in a new string array

        vector<string>arr;
        for(int x : nums)
        {
            arr.push_back(to_string(x));

        }



        //now doing a custom sort
        sort(all(arr), [](const string&a, const string&b)
    {
        return a+b > b+a;

    });


    if(arr[0] == "0")
    return "0";


    string ans;
    for(auto& ch :arr)
    {
        ans+=ch;
    }

    return ans;
}



int32_t main()
{
    ios::sync_with_stdio(false);

    cin.tie(0);


    vector<int>nums={3,30,34,5,9};

    string ans = largestNumber(nums);

    cout<<ans<<endl;
}