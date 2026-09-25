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
        int n,a,b;
        cin>>n>>a>>b;
    
        vector<int>arr(n);
        for(auto&x:arr)cin>>x;

        /*

        Capital = 0 initally
        We are given unconquered kingdoms

        We can change the location of your capital 

        Change location of capital c1 to any other c2 at cost of a* |c1-c2|

        from c1 to any unconquered kingdom c2 at cost of b*|c1-c2|

        We can't conquer a kingdom if there is an unconquered kingdom bw target and capital

        Determine min total cost to conquer all kingdoms 


        


        */

        
    }

    return 0;
}