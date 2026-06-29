#include<bits/stdc++.h>
#define ll long long
using namespace std;


    //LITTLE LITTLE DOUBT SOMEWHERE
int solve(vector<int>&a,int n)
{
    //Two guilds are considered different if a house that is in one guild and not in other 
    // he wants to know how many different non empty guilds are there in tree

    // a[i] = parent of ith house 
    /*

    dp[v] = max depth from root to vertex 'v'
    
    
    
    */

    //a[i]=parent of i+1 node

    //Building the tree
    vector<vector<int>>adj(n);

    for(int i = 0;i<n-1;i++)adj[a[i]-1].push_back(i+1);

    vector<int>depth(n);//depth[i] = depth of ith node from the root
    vector<int>dp(n);//dp[i] = deepest depth inside subtree of i
    vector<ll>ans(n);//ans[i] = number of valid guilds inside subtree i

    function<void(int)>dfs = [&](int node)
    {
        //Assume deepest node in the current subtree is itself
        dp[node] = depth[node];

        //Largest and second largest dp among all childrens
        int mx1 = depth[node];
        int mx2 = depth[node];

        ans[node] = 0 ;

        for(int child:adj[node])
        {
            depth[child] = depth[node]+1;

            dfs(child);


            //Guilds completely inside child's subtree
            ans[node]+=ans[child];

            //Deepest node in current subtree
            dp[node] = max(dp[node],dp[child]);

            if(dp[child] >= mx1)
            {
                mx2 = mx1;
                mx1 = dp[child];
            }
            else if(dp[child]>mx2)
            {
                mx2 = dp[child];
            }
        }
        // Guilds centered at current node
        // = 1 (radius 0) + second largest possible radius
        ans[node]+=(mx2-depth[node]+1);///DIDN'T UNDERSTOOD THIS LINE PROPERLY
    };

    dfs(0);
    return ans[0];
}

      
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

        vector<int>a(n-1);

        for(auto&x:a)cin>>x;

        cout<<solve(a,n)<<'\n';
    }
    return 0;
}