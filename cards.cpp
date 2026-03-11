#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> solve(vector<int>&a)
{
    int  n = a.size();

    /*
    There are n cards(even)

    n/2 players will play new card game

    Find the ways to distribute cards such that sum of values written of the cards will be equal for each player
    */
   vector<pair<int,int>>ans;

    vector<pair<int,int>>mp;
    for(int i=0;i<n;i++)
    {
        mp.push_back({a[i],i});
    }
    sort(mp.begin(),mp.end());

    for(int i =0;i<n/2;i++)
    {
        ans.push_back({mp[i].second+1 , mp[n-i-1].second +1});
    }
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&x:a)cin>>x;
    vector<pair<int,int>>ans = solve(a);
    for(auto & an: ans)
    {
        cout<<an.first<<" "<<an.second<<endl;
    }

    return 0;
}