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

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        /*

        Choose any odd index , and th remove k+1 element from arraty 

        We have to find the gcd of remaining array

        
        */

        if(n==1)cout<<a[0]<<'\n';

       
        
        else cout<<__gcd(a[0],a[n-1])<<'\n';
    }

    return 0;
}