#include<bits/stdc++.h>
using namespace std;

int minScoreTriangulation(vector<int>& values)
{
    //values[i] = value of ith vertex in clockwise direction

    //we will get n-2 triangles after polygon triangulation of n sided polygon

    //weight of each triangle = product of values of vertices
    //Total score = sum of those weights over all n-2 triangles

    //return the min sum of all possible triplets

    //n-2 possible triangle would be there
    int n = values.size();
    
    vector<vector<int>>dp(n,vector<int>(n,0));


    //since we need atleast 3 vertices for polygon to be triangle
    for(int len = 3; len <= n;len++)
    {
        for(int i =0; i+len-1< n; i++) // starting vertex of subpolygon
        {
            int j = len+i-1; // ending vertex of subpolygon

            dp[i][j] = INT_MAX;

            for(int k = i+1;k<j;k++)
            {
                //since , cost = left subPolygon + right subPolygon + current triangle

                int cost = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k];

                dp[i][j] = min(dp[i][j], cost);

            }
        }
    }
    return dp[0][n-1];
}

int main()
{

    vector<int>values = {1,2,3};

    cout<<minScoreTriangulation(values)<<endl;

    return 0;

}