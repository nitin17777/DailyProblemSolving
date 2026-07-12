#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> arrayRankTransform(vector<int>& a)
{
    int n = a.size();
    vector<int>b=a;

    sort(b.begin(),b.end());

    unordered_map<int,int>mp;
    int rank = 1;

    for(int x:b)
    {
        //To solve the duplicate issue,we will assign duplicates the same rank
        if(mp.find(x) == mp.end())mp[x] = rank++;
    }

    // 10 20 30 40
    // 1  2  3  4

    vector<int>ans;

    for(int i = 0;i<a.size();i++)
    {
        ans.push_back(mp[a[i]]);
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {40,10,20,30};
    vector<int>ans = arrayRankTransform(a);
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}