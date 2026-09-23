#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<ll>a(n);
    for(auto & x:a)
    {
        cin>>x;
    }

    /*

    In one operation choose 2 elements ai and aj and decrease each of them by one 

    Determine if we can make all elements equal to zero or not
    
    */

    ll maxi = *max_element(a.begin(),a.end());
    ll total = accumulate(a.begin(),a.end(),0LL);

    ll req = total-maxi;

    if(total%2==0 && maxi<=req)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}