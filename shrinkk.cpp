#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(int n)
{
    //choose mountain element and remove it from array

    //Score = max number of times that you can perform shrink operation

    //Return the permutation with max possible score

    vector<int>ans(n);
    ans[0] = 1;ans[n-1]=2;

    int k = 3;

    for(int i =1;i<n-1;i++)
    {
        ans[i] = k++;
    }

    return ans;
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

        vector<int>ans = solve(n);
        for(auto&x:ans)cout<<x<<" ";

        cout<<endl;
    
    }

    return 0;
}