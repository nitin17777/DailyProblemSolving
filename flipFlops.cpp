#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<ll>&a,ll c,ll k)
{
    int n = a.size();

    /*
    
    He has power = c and other monsters have power ai

    Ops : 
    1-> Kill an alive monster i fi ai < c and then c  = c+ ai
    2-> Throw flip flop and ai = ai + 1

    Return the max possible c after the battle ends
     
    */

    //To kill the weakest ones first and gain their power
    sort(a.begin(),a.end());

    for(int i = 0;i<n;i++)
    {
        if(a[i] <= c)
        {
            //How much we can boost : 
            ll boost = min(k,c-a[i]);

            c+= boost + a[i];
            k-= boost;
        }
        else return c;
    } 
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll c,k;
        cin>>n>>c>>k;

        vector<ll>a(n);
        for(auto&x:a)cin>>x;
        
        cout<<solve(a,c,k)<<endl;

    }
    return 0;
}