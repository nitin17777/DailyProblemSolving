#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>solve(vector<ll>&arr,ll k)
{
    /*we can either add k to every element or not

    Perform at most k operations to make gcd of elements of all elements of the array  > 1


    so we have to : ai + k*ci =0 mod(g) =>ci = -ai * (1/k)mod(k+1)

    */

    vector<ll>ans;


    for(ll g=2;;g++)//choosing smallest g that gcd of g and k == 1
    {
        if(__gcd(g,k) != 1)

        continue;


        //forcing each number to become divisible by g
        for(auto & i : arr)
        {
            while(i % g !=0)i+=k;
        }

        //returning new values now
        for(auto i : arr)
        {
            ans.push_back(i);
        }
        break;
    }
    return ans;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        vector<ll>arr(n);
        for(auto & x : arr)cin>>x;

        vector<ll>ans = solve(arr,k);

        for(auto & an : ans)cout<<an<<" ";

        cout<<endl;
    }
    return 0;
}
