#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(vector<int>&a,string s,int n)
{


    /*

    From j is reachable from i if : a[i] == j


    F(i) = number of black integer in the array

    
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

        string s;
        cin>>s;
        

        vector<int>ans = solve(a,s,n);

        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;

    
    }

    return 0;
}