#include<bits/stdc++.h>
#define int long long
using namespace std;

      
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto &x:a)cin>>x;

        // we want to choose exactly 2 different triads that don't share any keys
        //Determine the max number of ways to choose such triads 

        //Group triads with same amount of love
        //And then remove overlapping triads in a group

        //Two traids : x<y intersect only when y-x == 2 or y-x == 4

        //arr will store curr value calculated for every earlier starting index
        vector<int>arr;
        map<int,int>mp;

        int ans = 0;

        for(int i = 0;i < n-4;i++)
        {
            int curr = a[i] + a[i+2] - a[i+4];

            ans+=mp[curr];

            if(i>=2 && arr[i-2] == curr)ans--;
            if(i>=4 && arr[i-4] == curr)ans--;

            mp[curr]++;
            arr.push_back(curr);
        }
        cout<<ans<<'\n';
    }

    return 0;
}