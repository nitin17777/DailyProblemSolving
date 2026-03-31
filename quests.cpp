#include<bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int>& a,vector<int>&b)
{
    /*1st quest is always available for completion 

    ith quest is available for completion if : all previous quests have been completed
    
    For 1st completion he gets ai points
    Then for each subsquent completion of ith quest, he gets bi points

    He can do only k quests

    Calculate max possible experience he can get
    


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

        vector<int>a(n),b(n);

        cout<<solve(n,k,a,b);
    }
    return 0;
}