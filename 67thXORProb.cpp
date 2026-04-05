#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();

    int ans = 0;
    int maxi = 0;
    for(int i = 0;i<n;i++)
    {

        for(int j= i+1;j<n;j++)
        {
            //finding the greatest XOR value
            maxi = max(maxi,(a[i]^a[j]));
        }
    }
    return maxi;
}


int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<int>a(n);

        for(auto &x:a)cin>>x;

        cout<<solve(a)<<endl;
        
    }
}