#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(vector<int>&a,int n)
{
    /*

    Base area = 1cm2
    bw ith and (i mod n) + 1th vessel there is a connection of hi cm 
    
    
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

        vector<int>(n);
        for(auto &x:a)cin>>x;

        vector<int>ans = solve(a,n);
        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;
    
    }

    return 0;
}