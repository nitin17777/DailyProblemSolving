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


        vector<int>a(n);
        

        vector<vector<int>>freq(n+1);

        for(int i = 0;i<n;i++)
        {
            cin>>a[i];

            freq[a[i]].push_back(i);
        }

        vector<int>b(n,0);
        int cnt = 1;
        bool ok = true;

        for(int i = 1;i<=n;i++)
        {
            if((int)freq[i].size()%i)
            {
                ok = false;
                break;
            }

            int c = 0;

            while(c < (int)freq[i].size())
            {
                for(int v = 0;v<i;v++)
                {
                    b[freq[i][c]] = cnt;
                    c++;
                }
                cnt++;
            }
        }

        if(!ok)cout<<-1<<endl;

        else
        {
            for(auto &x:b)cout<<x<<" ";

            cout<<endl;
        }
            
    }

    return 0;
}