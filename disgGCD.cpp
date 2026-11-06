#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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
        for(auto &x:a)cin>>x;
        
        
        //Operation  : choose any x such that: gcd(ai,x) = 1 and increase ai by x 

        //sum of overall x used should not exceed sum of array
        //And we can perform atmost n+10 operation

        int total = accumulate(a.begin(),a.end(),0);

        //Find the final obtained array 

    }

    return 0;
}