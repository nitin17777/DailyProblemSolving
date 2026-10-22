#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>pos;
        
        string s;
        cin>>s;

        for(int i=0;i<n;i++)if(s[i] == '*')pos.push_back(i);

        int k = pos.size();

        if(k==0)
        {
            cout<<0<<'\n';
            continue;
        }

        //Removing space caused by consecutive sheep. HONSELY DIDN'T JUST UNDERSTOOD THIS PARTICULAR LINE 
        for(int i = 0;i<k;i++)pos[i] -= i;

        int median = pos[k/2];

        /*

        In one move -> Move any sheep to left or right if possible 

        Determine minimum number of moves we need to make to complete the level
        
        */

        ll ans = 0;
        for(int i =0;i<k;i++)ans += abs(pos[i] - median);
        cout<<ans<<'\n';
    }
    return 0;
}