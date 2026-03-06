#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n)
{
    //Find the permutation such that no (i,j) exists in a wasy that: pi divides pj and pi+1 divides pj+1

    vector<int>ans;
    int l=1,r=n;
    for(int i = 1;i<=n;i++)
    {
        if(i&1)
        {
            ans.push_back(l);
            l++;
        }
        else
        {
            ans.push_back(r);
            r--;
        }
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
        vector<int>ans= solve(n);
        for(auto &x:ans)cout<<x<<" ";

        cout<<endl;

    }
    return 0;
}