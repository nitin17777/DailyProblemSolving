#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<vector<int>> merge(vector<vector<int>>& a)
{
    int n = a.size();

    vector<vector<int>>ans;

    sort(a.begin(),a.end());

    int lastSec = a[0][1];
    int lastOne = a[0][0];

    for(int i=1;i<n;i++)
    {
        if(lastSec >= a[i][0])
        {
            if(a[i][1]>lastSec)lastSec=a[i][1];
        }

        else
        {
            ans.push_back({lastOne,lastSec});
            lastOne=a[i][0];
            lastSec=a[i][1];
        }
    }

    ans.push_back({lastOne,lastSec});
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{1,4},{2,3}};

    vector<vector<int>>ans = merge(a);

    for(auto & x:ans)
    {
        for(auto&y:x)cout<<y<<" ";
        cout<<endl;
    }
    cout<<endl;


    return 0;
}