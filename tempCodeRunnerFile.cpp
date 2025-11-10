#include<bits/stdc++.h>
using namespace std;

bool isPossible(int k,vector<int>&h)
{
    /* 
    At time 0, we are on tower heights[k]
    Water level rises by 1 unit each second
    //if water level  > height of tower, you perish

    We can jump from tower i to tower j in |hi - hj|seconds
    And teleportation can start the moment we just arrive at tower j

    
    Goal is to reach any tower with max height before water covers me


    */
    int n = h.size();

    sort(h.begin(),h.end());
    int i = 0;

    while(h[i] != k)i++;

    //we reached the tower in which we are at

    //now check and reach the end of the array
    int diffs = 0;

    for(int k = i;k<n-1;k++)//seeing difference till we reach the end
    {
        diffs += h[i+1] -h[i];
    }

    return i >= diffs;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>h(n);
        for(auto&x: h)cin>>x;

        cout<<(isPossible(k,h)? "Yes" : "No")<<endl;

    }    
    return 0;
    
}
