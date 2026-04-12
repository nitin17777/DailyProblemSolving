#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<ll>&a,int n)
{
    /*

    Determine if we can arrange a such that min({a1,a2,..ai}) == gcd(ai+1, ai+2..an)

    */

    sort(a.begin(),a.end());

    ll mini = a[0];

    vector<ll>multi;

    bool removed = false;

    for(int i = 0;i<n;i++)
    {
        if(a[i] == mini && !removed)
        {
            removed = true;
            continue;
        }

        if(a[i] %mini ==0)
        {
            multi.push_back(a[i]);
        }
    }

    //Now check if their gcd == mini

    if(multi.empty())return false;

    ll g = multi[0];

    for(int i = 1;i<multi.size();i++)
    {
        g = __gcd(g,multi[i]);
    }
    return g==mini;
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

        cout<<(solve(a,n)?"Yes":"No")<<endl;    
    }

    return 0;
}




