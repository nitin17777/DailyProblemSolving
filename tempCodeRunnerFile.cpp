#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& a,int c)
{
    int n = a.size();

    //If WE don't type a word for c seconds, everything disappears

    // word disappears after we don't type after c seconds

    int cnt=0;

    for(int i = 0;i<n;i++)
    {
        if(i==0)cnt++;

        else
        {
            if(a[i] - a[i-1] <= c)cnt++;

            else cnt = 1;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n,c;
    cin>>n>>c;

    vector<int>a(n);
    for(auto&x : a)cin>>x;

    cout<<solve(a,c)<<endl;
    
    return 0;
}