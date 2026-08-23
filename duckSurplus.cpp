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

        vector<ll>a(n);
        for(auto&x:a)cin>>x;

        // Choose piles such that left pile contains more ducks than right pile

        //When ai > ai+1 ,replace(ai,ai+1) wiht ai+1, ai + ai+1

        for(int i=0;i<n-1;i++)
        {

            if(a[i]>a[i+1])
            {
                ll temp = a[i+1];
                a[i+1]+=a[i];
                a[i] = temp;
            } 
        }
        cout<< a[n-1] << '\n';
    }

    return 0;
}