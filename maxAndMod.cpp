#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(int n)
{

    vector<int>ans;

    if(n%2 == 0)
    {
        ans.push_back(-1);
        return ans;
    }

    //fidn the permutation of length n such that max(pi,p i-1)mod i = i-1

    ans.push_back(n);
    for(int i = 1;i<n;i++)
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

        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;
    }

    return 0;
}

