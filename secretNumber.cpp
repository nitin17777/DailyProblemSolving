#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> secretNum(ll n)
{
   //to make it a secret number he appended a positive number of zeroes to the right of it(x) thus obtaining a new number (y)
   //and then:n = x+y......Find all the suitable x that Vadim could have thought of for the given n
   //return 0 if no 
   
   vector<ll>ans;

   //n = x+ x*10^k = x(1+10^k) => x = n/(1+10^k)....

   // if(n % 1+10^k == 0) for any value of k

ll power = 10;
while(power < n)
{
    ll divisor = 1 + power;
    if(n % divisor == 0)
    {
        ll x = n / divisor;
        ans.push_back(x);
    }
    power*=10;
}

sort(ans.begin(),ans.end());
return ans;
}

int main()
{

    ll t;
    cin>>t;

    while(t--)
    {

        ll n;
        cin>>n;
        
        
        vector<ll>ans = secretNum(n);

        if(ans.empty())
        {
            cout<<'0'<<endl;
        }
        else
        {
            cout<<ans.size()<<endl;
            for(auto& noo: ans)
            {
                cout<<noo<<" ";
            }
        cout<<endl;
        }
    }
    return 0;        
    }
