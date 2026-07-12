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

        if(n==2)
        {
            cout<<-1<<'\n';
            continue;
        }
        else if(n==1)
        {
            cout<<1<<'\n';
            continue;
        }
        //Construct such array : sum is divisible by all elements in the array


        //But each element must be distinct
        // for(int i = 0;i<n;i++)cout<<1<<" ";

        else 
        {
            vector<ll>a;
            a.push_back(1);
            a.push_back(2);
            a.push_back(3);

            for(ll k = 3; k < n; k++)a.push_back(a.back() * 2);

            for(auto &x:a)
            {
                cout<<x<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}