#include<bits/stdc++.h>
using namespace std;


/* TLE EXCEEDED IN THIS METHOD NT :) 


int maxim(vector<int>&a,vector<int>&b)
{
    int n = a.size(),m = b.size();
    int maxi = 0;

    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int diff = abs(a[i]-b[j]);
            maxi = max(maxi,diff);
        }
    }
    return maxi;
}

int maxDistance(vector<vector<int>>& a)
{

    int m = a.size();

    //Return the max distance bw two integers such that both are taken from different arrays

    // Fix one matrix and find max distance with one at at once
    int ans = 0;

    for(int i=0;i<m;i++)
    {
        for(int j = i+1;j<m;j++)
        {
            ans = max(ans,maxim(a[i],a[j]));
        }
    }
    return ans;
}
    */

//Just checking the extemums
int maxDistance(vector<vector<int>>& a)
{
    int minVal = a[0][0],maxVal = a[0].back();

    int ans = 0; 

    for(int i = 1;i<a.size();i++)
    {
        int currMin = a[i][0];

        int currMax = a[i].back();

        ans = max(ans, abs(currMax - minVal));
        ans = max(ans,abs(maxVal - currMin));

        minVal = min(minVal, currMin);
        maxVal = max(maxVal, currMax);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{1,2,3},{4,5},{1,2,3}};
    cout<<maxDistance(a)<<endl;
    return 0;
}