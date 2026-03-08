#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPerfect(ll n)
{
    ll sq = sqrtl(n);

    return (sq* sq == n);
}

vector<int>solve(int n)
{
    //Perfect if for each index i,it satisfies :Sum of first pi elements is not a perfect square
    ll sq = 1LL * n*(n+1)/2;

    //if sum of all elements is a perfect square we can never form the required permutation
    if(isPerfect(sq))return {-1};

    vector<int>ans(n);
    for(int i = 0;i<n;i++)ans[i] = i+1;

    ll prefix = 0;
    for(int i = 0;i<n-1;i++)
    {
        if(isPerfect(prefix + ans[i]))
        {
            swap(ans[i],ans[i+1]);
        }

        prefix+=ans[i];
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