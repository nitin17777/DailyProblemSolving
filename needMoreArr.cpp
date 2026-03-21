#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();

    //Remove elements in such a way that this algo creates as many arrays as possible

    int last = -1,ans = 0;

    for(int i = 0;i<n;i++)
    {
        if(a[i] - last > 1)
        {
            ans++;
            last = a[i];
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
        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a)<<endl;
    }
    return 0;
}