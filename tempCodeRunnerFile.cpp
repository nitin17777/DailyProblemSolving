#include<bits/stdc++.h>
using namespace std;

int count(vector<int>&a)
{
    int cnt = 0;
    if(a[0] ==1)cnt=1;

    for(int i = 1;i < a.size();i++)
    {
        if(a[i-1] != 1)
        {
            if(a[i] == 1)cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    //if two 1s are consecutive -> count 1 only

    //else also just count 1
    int sz = m*n;

    vector<int>a(sz);
    for(auto &x:a)cin>>x;

    int ans = count(a);

    vector<int>b(sz);
    for(auto &x:b)cin>>x;

    ans+=count(b);
    
    cout<<ans<<endl;
    return 0;
}