#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n)
{
    //construct the permutation such that a1 mod a2  > a2 mod3 > ....


    // since x%(x-1) is always 1 except for x=2 which will be 0

    //So a normal reverse order would work
    vector<int>ans;

    for(int i = n;i>=1;i--)
    {
        ans.push_back(i);
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
        for(auto& x:ans)cout<<x<<" ";

        cout<<endl;
        
    }
    return 0;
}