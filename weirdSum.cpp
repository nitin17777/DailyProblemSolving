#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dist(vector<pair<int,int>>&a)
{
    int ans = 0;
    for(int i = 0;i<a.size();i++)
    {
        for(int j = 0;j<a.size();j++)
        {
            int a1 = a[i].first , b1 = a[i].second;
            int a2 = a[j].first, b2 = a[j].second;

            ans+=abs(a1-a2)+abs(b1-b2);
        }
    }
    return ans;
}


int solve(map<int,vector<pair<int,int>>>&a)
{
    //sum the distance bw cell having same number 


    int ans = 0;

    for(auto&arr:a)
    {
        ans+=dist(arr.second);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n,m;
    cin>>n>>m;

//     map<int,vector<pair<int,int>>>idx;

//    for(int i=0;i<n;i++)
//    {
//         for(int j = 0;j<m;j++)
//         {
//             int x;
//             cin>>x;
//             idx[x].push_back({i+1,j+1});
//         }
//    }

//    cout<<solve(idx)/2<<'\n';


    const int MAXC =100000;

    vector<int>rows(MAXC+1);
    vector<int>cols(MAXC+1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin >> x;

            rows[x].push_back(i);
            cols[x].push_back(j);
        }
    }

    ll ans = 0;
    



    return 0;
}