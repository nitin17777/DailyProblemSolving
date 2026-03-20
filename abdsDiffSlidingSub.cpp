#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> minAbsDiff(vector<vector<int>>& g, int k)
{
    int m = g.size(),n=g[0].size();

    if(k == 1)
    {
        return vector<vector<int>>(m,vector<int>(n,0));
    }

    //Now within every contiguous submat of grid, compute min abs diff bw any two values 
    
    //Return array ans of size (m-k+1) * (n-k+1) ,where ans[i][j] = min abs differnece of submat with top left corner (i,j) in grid

    vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));

    for(int i = 0; i <= m-k; i++)
    {
        for(int j = 0; j <= n-k; j++)
        {
            vector<int>vals;
            for(int x = i; x<i+k; x++)
            {
                for(int y = j; y<j+k; y++)
                {
                    vals.push_back(g[x][y]);
                }
            }

            //Got all the elements from that required submatrix
            sort(vals.begin(),vals.end());


            //Finding min adjacent difference 

            int minDiff = INT_MAX;

            for(int t = 1;t<vals.size();t++)
            {

                //AS different number is given in the question
                if(vals[t] != vals[t-1])
                {
                    minDiff = min(minDiff,vals[t]-vals[t-1]);
                }

            }
            if(minDiff == INT_MAX)minDiff = 0;
                
            ans[i][j] = minDiff;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,-2,3},{2,3,5}};
    
    vector<vector<int>>ans = minAbsDiff(g,2);

    for(auto& an :ans)
    {
        for(auto & x:an)cout<<x<<" ";

        cout<<endl;
    }
    return 0;
}