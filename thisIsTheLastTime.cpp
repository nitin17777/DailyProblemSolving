#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
int solve(int k)
{
    

    k = Initial number of coins


    We can play at casino i iff: li <= x(current money) <= ri

    After playing -> number of coins becomes real i 


    We can visit one casino only once
    
    Determine the max number of coins we can obtain


    Approach:

    Determine the condtions which the current money satisfies and take the one with max real

    if real == current money of any casino, no benefit in going over there , so simply ignore
}
    */

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<tuple<int,int,int>>p(n);
        
        for(int i = 0 ;i<n;i++)
        {
            int l,r,real;
            cin>>l>>r>>real;

            p[i] = {l,r,real};
        }

        //Default sort on the basis of l 
        sort(p.begin(),p.end());

        int curr = k;

        for(int i = 0;i<n;i++)
        {
            // Accessing the tuple values
            int l = get<0>(p[i]), r = get<1>(p[i]), real = get<2>(p[i]);

            //Because not possible to find any valid casino afterwards
            if(l > curr)break;

            curr = max(curr,real);
        }
        cout<<curr<<endl;
    }

    return 0;
}
