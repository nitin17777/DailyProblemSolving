#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>a,int n)
{

    /*

    to maximise total contribution of max element, put it as early as possible
    */

    ll maxi = *max_element(a.begin(),a.end());
    
    unordered_set<int>st;
    for(auto & x:a)st.insert(x);

    //finding mex of the array
    ll mex = 0;
    while(st.count(mex))mex++;

    ll ans = 1LL *n *maxi;//since it is at starting of the arrray

    ans+= 1LL * mex*n;//Considering for all right now

    //but it didn't contributed to elements after it
    ans -= 1LL * mex * (mex+1)/2;

    if(maxi == mex-1)ans+=1;

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
        int n;
        cin>>n;

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,n)<<endl;    
    }

    return 0;
}