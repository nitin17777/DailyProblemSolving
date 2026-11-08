#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries)
{
    
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>logs = {{1,3},{2,6},{1,5}};
    vector<int>q= {10,11};
    vector<int>ans = countServer(3,logs,5,q);
    for(auto&x:ans)cout<<x<<" ";


    cout<<endl;

    return 0;
}