#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    /*

    f(c) = max possible mex(c) that can be achieved by performing this operation exacly once: 

    choose an array b and set ci = ci mod bi 


    
    */
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
        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    
    }

    return 0;
}
