#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int>&a,int n)
{
    // f(l,r) = MEX(al,....ar)

    //For every point i , MEX of prefix must be different from MEX of suffix


    //If one zero -> Always possible

    vector<int>cnt(n+1);

    for(auto & x:a)cnt[x]++;


    if(cnt[0] == 0) return false;
    else if(cnt[1] > 0) return true;
    else 
    {
        if(cnt[0] == 1)return true;
        else return false;
    }
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
        for(auto&x :a)cin>>x;

        cout<<(solve(a,n)?"Yes":"No")<<endl;

    
    }

    return 0;
}