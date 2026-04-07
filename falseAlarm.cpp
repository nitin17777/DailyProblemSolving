#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&a,int x)
{
    int n = a.size();

    // HE can open all closed door for x seconds for once

    //determine if he can pass through all the doors

    //Distance between 1st and last door must be less than equa to x

    int fs = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i] == 1)
        {
            fs = i;
            break;
        }
    }


    int ls =n-1;

    for(int i = n-1;i>=0;i--)
    {
        if(a[i] == 1)
        {
            ls = i;
            break;
        }
    }

    int diff = ls - fs+1;
    return diff <= x;

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x;
        cin>>n>>x;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        cout<<(solve(a,x)?"Yes":"No")<<endl;
    
    }

    return 0;
}