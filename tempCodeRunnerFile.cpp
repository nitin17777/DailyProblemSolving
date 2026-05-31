#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    //Find k such that only distinct elements are there in array at last

    //If odd number is there -> ans = 2
    bool odd = false;
    bool even = false;
    for(auto&x:a)
    {
        if(x%2 != 0)odd = true;
        else even  = false;
    }

    if(odd && even)return 2;


    // if all odd

    ll k = 2;

    while(true)
    {

        set<ll>s;

        for(auto &x:a)
        {
            s.insert(x%k);
        }

        if(s.size() == 2)
        {
            return k;
        }
        k*=2;
    }
    return 0;
    
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

        vector<int>a(n);
        for(auto& x:a)cin>>x;

        cout<<solve(a,n)<<endl;    
    }

    return 0;
}