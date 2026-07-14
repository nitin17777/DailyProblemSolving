#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k,x;
    cin>>n>>k>>x;

    vector<ll>a(n);
    for(auto &x:a)cin>>x;

    //Stable if : IF in sorted aray no two adjacent elements will differ by more than x
    sort(a.begin(),a.end());

    //Cut is possible only if: a-b/2 <= x


    ll groups =1;
    vector<ll>need;
    for(int i = 1;i<n;i++)
    {
        ll gap = a[i]-a[i-1];
    
        if(gap > x)
        {
            groups++;
            need.push_back((gap-1)/x);
        }
    }

    sort(need.begin(),need.end());


    for(auto&req:need)
    {
        if(k>=req)
        {
            k-=req;
            groups--;
        }
    }
    cout<<groups<<'\n';


    return 0;
}