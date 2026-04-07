#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&a,vector<int>&b)
{
    int n = a.size();

    /*

    We can perform one of these in one step : copy the value of two adjacent elemnts into each other

    Determine if permutation p is generating a
    */

    map<int,int>pos;
    int lst = -1;
    for(int i = 0;i<n;i++)
    {
        pos[a[i]] = i;
    }

    for(int i = 0;i<n;i++)
    {
        if(lst > pos[b[i]])return false;

        lst = pos[b[i]];
    }
    return true;
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

        vector<int>p(n),a(n);

        for(auto& x:a)cin>>x;
        for(auto& x:p)cin>>x;


        cout<<(solve(a,p)?"Yes":"No")<<endl;

    
    }

    return 0;
}