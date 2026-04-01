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

    int res = 0,sum = 0,mx = 0;

    for(int i=0;i<min(n,k);i++)
    {
        sum+=a[i];

        mx = max(mx,b[i]);

        res = max(res,sum + mx* (k-i-1));
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        cout<<solve(n,k,a,b)<<endl;
    }

    return 0;
}