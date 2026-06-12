#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int>&a,int n,int k)
{
    /*

    On the first move : any element from array can be removed 

    Previous element = x
    Now choose y such that 0 <= y-x <=k and remove it from array
    And player who can't make the move loses


    Determine if first move can be made such that 2nd player always win no matter what after making the first move 
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
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<(solve(a,n,k)?"Yes":"No")<<'\n'
    }

    return 0;
}