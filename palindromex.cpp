#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>&a,int n)
{
    

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

        vector<int>a(n*2);
        for(auto & x:a)cin>>x;

        cout<<solve(a,n*2)<<endl;
    
    }

    return 0;
}