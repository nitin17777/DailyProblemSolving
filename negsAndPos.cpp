#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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

        ll sum = 0;

        vector<ll>a(n);
        ll mini = LLONG_MAX;

        for(auto&x:a)
        {
            cin>>x;

            sum+=abs(x);
            mini=min(mini,abs(x));
        }
        /*

        -9 1 6 7 -8 9 10

        if(even number of negatives => simply return the sum)

        -1 -5 -5 2 4

        //if (odd)return sum - least number (absolute)
        
        */

        ll negs=0;
        for(auto&x:a)if(x<0)negs++;

        if(negs%2==0)cout<<sum<<'\n';
        else cout<<sum-2*mini<<'\n';      
    }

    return 0;
}