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

        vector<ll>a(n);
        for(auto& x:a)cin>>x;

        /*
            Take such i,j : ai + aj is odd , then : ai-- and aj++

            //Find the max posssible beauty of gifts 


            
            EO -> O, this woud be of only use to us

            After each operation, number of evens and odds remains conserved
               
            
            //When all numbers have same parity -> Answer is simply the max element

            If atleast one even and odd is there ->
        */


        //number odd elements never change
        
        ll maxi = *max_element(a.begin(),a.end());
        ll total = accumulate(a.begin(),a.end(),0LL);

        vector<ll>even,odd;
        for(auto&x:a)
        {
            if(x%2 == 0)even.push_back(x);
            else odd.push_back(x);
        }


        if(odd.empty() || even.empty())
        {
            cout<<maxi<<'\n';
            continue;
        }
        cout<<total-odd.size()+1<<'\n';
    }

    return 0;
}