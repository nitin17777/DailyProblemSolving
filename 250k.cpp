#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>&a,int n)
{
    /*

    k boxes go to n/k th truck

    
    
    
    */
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

        cout<<solve(a,n)<<'\n';
    
    }

    return 0;
}