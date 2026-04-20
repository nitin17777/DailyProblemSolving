#include<bits/stdc++.h>
#define ll long long
using namespace std;



//Didn't understood the solution properly actually
vector<ll>solve(vector<ll>&a,vector<ll>&b)
{

    int n =a.size();

    /*

        a is already increasing array

        Determine how many points are contained in exactly ki segments

        Each segment covers all integer points in between 

    */ 

    unordered_map<ll,ll>freq;

    //Contribution of given points

    for(int i =0 ;i <n;i++)
    {
        ll left = i+1;
        ll right = n-i;

        ll val = right * left - 1;

        freq[val]++;
    }

    //Gap contribution
    for(int i = 0;i<n-1;i++)
    {
        ll gap = a[i+1] - a[i] - 1;

        if(gap > 0)
        {
            ll left = i+1;
            ll right = n-(i+1);

            ll val = left* right;
            freq[val]+=gap;
        }
    }

    vector<ll>ans;
    for(auto& x:b)
    {
        ans.push_back(freq[x]);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;

        vector<ll>a(n),b(q);
        for(auto& x:a)cin>>x;
        for(auto& x:b)cin>>x;

        vector<ll>ans = solve(a,b);

        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;
    }

    return 0;
}