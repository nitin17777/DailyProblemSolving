#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
///Didnt understood much of this 
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

        string s;
        cin>>s;

        //Choose x = 0 or 1 , and l,r and set all elements in this range = x

        //We can tweak values of atmost k chars in string 

        //max possible diversity of resulting string 

        //Diversity = number of distinct strings that can be obtained by peforming the above operation at most once
        

        int x = 0;
        for(auto c:s)if(c=='0')x++;

        x= min(max(x,n-x) + k,n);
        int y = n-x;

        ll ans = 1LL * x * (x+1)/2 + 1LL * y * (y+1)/2 +1;

        cout<<ans<<'\n';
    }

    return 0;
}