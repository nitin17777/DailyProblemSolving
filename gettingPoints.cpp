#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n,int P,int l,int t)
{

    /*

    earn P points in n days to not get expelled

    each practical = t points 
    each lesson = l points
    

    when he decides to study -> he can complete not more than 2 tasks which are not completed yet

    
    Determine the max number of days he can rest

    */

    int c = (n+6)/7;

    auto calc = [&](int k)
    {
        return k*l + min(2*k,c)*t;
    };

    int lf = 0, rg = n;

    while(rg - lf > 1)
    {
        int mid = (lf+rg)/2;

        //if mid days are enough to reach required points 
        if(calc(mid) >= P)rg  = mid;
        
        else lf = mid;
    }
    return n-rg;
}

      
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,P,l,t;
        cin>>n>>P>>l>>t;

        cout<<solve(n,P,l,t)<<endl;
    }

    return 0;
}