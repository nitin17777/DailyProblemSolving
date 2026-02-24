#include<bits/stdc++.h>
using namespace std;

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet)
{
    //richer[i] = (ai,bi) : ai has more money than bi


    //Return ans : ans[x] = y if y is the least quiet person


    //find the min quiet value with all the ancestors of node x
    int n = quiet.size();

    vector<vector<int>>adj(n);

    for(auto &r:richer)
    {
        int richP = r[0];
        int poorP = r[1];


        adj[poorP].push_back(richP);
    }

        vector<int>ans(n,-1);//To store the index of the least quiet person


        function<int(int)>dfs = [&](int node)
        {

            //If answer is already computed 
            if(ans[node] != 1)return ans[node];


            //Initially assuming that person itself is the most silent
            ans[node] = node;

            for(int richerP : adj[node])
            {
                int candidate = dfs(richerP);


                if(quiet[candidate] < quiet[ans[node]])
                {
                    ans[node] = candidate;
                }
            }
            return ans[node];
        };

        for(int i = 0; i < n;i++)dfs(i);

        return ans;

    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    vector<vector<int>>richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int>quiet = {3,2,5,4,6,1,7,0};

    vector<int>ans = loudAndRich(richer,quiet);
    for(auto  & x:ans)cout<<x<<" ";

    cout<<endl;
    
    return 0;
}