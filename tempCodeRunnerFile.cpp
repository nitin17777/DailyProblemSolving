#include<bits/stdc++.h>
using namespace std;

int maxi(vector<int>& a)
{
    int n = a.size();
    /*
    Height of tower from ith admirer = ai
    
    She can: Take 1<= i != j<=n ,ai + aj is odd and ai>0, then decrease ai by 1 
    and increase aj by 1

    find the max possible beauty of gifts after any number of operations

    */
   int odd = 0,even = 0;

   int s = accumulate(a.begin(),a.end(),0);

   int aMax = *max_element(a.begin(),a.end());

    for(auto& x: a)
    {
        if(x%2 != 0)odd++;
        else even++;
    }

    if(odd == n || even == n)return aMax;

    else return s - odd +1;
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
        cin>>n;
        
        vector<int>a(n);
        for(auto &x:a)cin>>x;

        cout<<maxi(a)<<endl;
    }
    return 0;
    
}