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
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>a(n+1);
        for(int i =1;i<=n;i++)cin>>a[i];

        vector<vector<int>>adj(n+1);

        for(int i=1;i+x<=n;i++)
        {
            adj[i].push_back(i+x);
            adj[i+x].push_back(i);
        }
        
        for(int i=1;i+y<=n;i++)
        {
            adj[i].push_back(i+y);
            adj[i+y].push_back(i);
        }


        vector<int>comp(n+1,-1);
        int id = 0;

        for(int i = 1;i<=n;i++)
        {
            if(comp[i] != -1)continue;



            queue<int>q;
            q.push(i);
            comp[i] = id;

            while(!q.empty())
            {
                int v = q.front();
                q.pop();


                for(int u : adj[v])
                {
                    if(comp[u] == -1)
                    {
                        comp[u] = id;
                        q.push(u);
                    }
                }
            }
            id++;
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) 
        {
            if (comp[i] != comp[a[i]])
            {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}


// 5 4 3 2 1
// 1 2 3 4 5