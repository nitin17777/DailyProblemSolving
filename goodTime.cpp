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
        ll n;
        cin>>n;

        //find y: y is good and x* y is good

        string s = to_string(n);

        ll p = 1;
        int len = s.size();
        while(len--)
        {
            p*=10;
        }
        cout<<p+1<<'\n';
    }

    return 0;
}