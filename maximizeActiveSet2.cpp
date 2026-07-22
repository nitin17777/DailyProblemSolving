#include<bits/stdc++.h>
#define ll long long
using namespace std;


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>q={{0,3},{0,2},{1,3},{2,3}};
    vector<int>ans = maxActiveSectionsAfterTrade("0100",q);
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;
    
    return 0;
}