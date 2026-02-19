#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(vector<int>&a,vector<int>&b)
{
    //We must defeat a monster at level i to reach level i+1
    //And to defeat ith monster ,we need to deal it bi sword strikes 

    //ai = strength
    //bi = required swords strikes 

    //score = difficulty(x) * levels comepleted
    int n = a.size();


    sort(a.rbegin(),a.rend());

    ll ans = 0; // Max score
    ll sum  = 0; // total words used so far
    int h = 0; //Levels completed till now


    //Trying each sword as difficulty
    for(int i = 0;i<n;i++)
    {
        while(h<n && sum + b[h] <= i+1)
        {   
            sum+=b[h];//Add required strikes
             h++;//Complete next level
        }

        ans = max(ans, 1ll* a[i]*h);
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
        vector<int>a(n),b(n);
        for(auto &x:a)cin>>x;
        for(auto &x:b)cin>>x;

        cout<<solve(a,b)<<endl;
        
    }
    return 0;
}