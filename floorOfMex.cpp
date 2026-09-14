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


        vector<int>a(n);
        for(auto & x:a)cin>>x;

        /*

        f(S,x) = mex({y/x} : y belongs to S)

        We have array a of length n such that: ak = f(A,k) for every 1<= k <= n 


        We have to construct any subset B such that f(B,k) = ak for every k 
        


        
        
        */
    
    }

    return 0;
}