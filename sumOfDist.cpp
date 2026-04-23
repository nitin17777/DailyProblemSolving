#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<long long> distance(vector<int>& nums)
{

    int n = nums.size();


    vector<ll>ans(n,0);

    /*

    arr[i] = sum of |i - j| over all j such that nums[j] = nums[i] and i != j


    //Prepare a list of all indices where nums[i] has occured
    


*/

    unordered_map<int,vector<int>>mp;


    //Indices array of where that number hs appeared in total
    for(int i = 0;i<n;i++)
    {
        mp[nums[i]].push_back(i);
    }

    for(auto & it: mp)
    {
        vector<int>&curr = it.second;
        int m = curr.size();

        if(m == 1)
        {
            ans[curr[0]] = 0;
            continue;
        }

        vector<ll>pref(m,0);
        pref[0] = curr[0];

        //Prefix sum of indices array
        for(int i = 1; i<m;i++)pref[i] = pref[i-1] + curr[i];

        for(int i = 0;i<m;i++)
        {
            ll left = 0, right = 0;

            if(i>0)
            {
                left = (ll)i * curr[i] - pref[i-1];
            }

            if(i<m-1)////
            {
                right = (pref[m-1] - pref[i]) - (ll)(m-i-1)*curr[i];
            }

            ans[curr[i]] = left+ right;
        }
    }
    return ans;
}


/*

        Brute force appproach  : TLE


ll find(vector<int>&a,int x)
{
    ll sum = 0;

    

    for(auto & num : a)
    {
        sum += abs(num-x);
    }
    return sum;
}

vector<long long> distance(vector<int>& nums)
{

    int n = nums.size();


    vector<ll>arr;

    /*

    arr[i] = sum of |i - j| over all j such that nums[j] = nums[i] and i != j


    //Prepare a list of all indices where nums[i] has occured
    

    unordered_map<int,vector<int>>mp;


    //Indices array of where that number hs appeared in total
    for(int i = 0;i<n;i++)
    {
        mp[nums[i]].push_back(i);
    }


    for(int i = 0;i<nums.size();i++)
    {
        vector<int>curr = mp[nums[i]];

        //sum of difference of indices
        ll found = find(curr,i);

        arr.push_back(found);
    }
    return arr;
}
*/

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a ={1,3,1,1,2};
    vector<ll>ans = distance(a);

    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}