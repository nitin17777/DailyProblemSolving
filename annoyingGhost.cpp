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

        vector<int>a(n),c(n);

        for(auto& x:a)cin>>x;        

        //Find min possible ops in second stage among all processes

        set<int>s;
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;
            s.insert(x);
        }

        bool y  = true;

        for(int i =0; i <n;i++)
        {
            auto it = s.lower_bound(a[i]);


            if(it == s.end())
            {
                y=false;
                break;
            }

            c[i] = *it;
            s.erase(it);
        }

        if (!y)
        {
            cout << -1 << '\n';
            continue;
        }

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j) 
            {
                if (c[i] > c[j]) {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}