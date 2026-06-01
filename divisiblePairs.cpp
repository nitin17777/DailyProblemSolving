#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<int>&a,int n,int x,int y)
{
    /*
    
    Two indices are beautiful if : ai + aj is divisible by x and ai-aj is divisible by y 

    find the number of beautiful pairs in array a
    
    */
   ll cnt = 0;

//    for(int i = 0;i<n;i++)
//    {
//         for(int j = i+1;j<n;j++)
//         {
//             if(((a[i] + a[j]) % x == 0) && (a[i]-a[j])%y == 0)cnt++;
//         }
//    }

    //Optimisation: Above code was correct but O(n^2)
    map<pair<int,int>,int>mp;

    for(int i =0;i<n;i++)
    {
        int rx = a[i] %x;
        int ry = a[i] %y;

        pair<int,int>need = {(x-rx)%x, (ry)};

        cnt+=mp[need];
        mp[{rx,ry}]++;
    }
   return cnt;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        cout<<solve(a,n,x,y)<<endl;    
    }

    return 0;
}