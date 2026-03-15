#include<bits/stdc++.h>
using namespace std;

bool solve(int n,vector<int>&a)
{
    //Can we rearrange the grid such that no row or col consits of n numbers of same value

    ///total candies = n*n
    unordered_map<int,int>freq;
    for(auto& x:a)freq[x]++;

    int maxi = 0;
    for(auto& x:freq)
    {
        maxi = max(maxi,x.second);
    }
    return maxi <= n*n - n;
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

        vector<int>a(n*n);

        for(int i = 0;i<n*n;i++)
        {
            cin>>a[i];
        }
        cout<<(solve(n,a)? "Yes":"No")<<endl;        
    }
    return 0;
}