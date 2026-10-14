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
        int a,b;
        cin>>a>>b;

        /*

        Each sandwich = one cheese + one sausage
        for each sandwich number of slices of chees > number of sausages

        Max number of sandwiches he can make
    
        */
       if(a<=b)cout<<-1<<'\n';
       else cout<<min(b,a-b)<<'\n'; 
    }

    return 0;
}