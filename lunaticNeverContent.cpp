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
        for(auto&x:a)cin>>x;

        if(n==1)
        {
            cout<<0<<'\n';
            continue;
        }

        //find biggest x such that f(a,x) is a plaindrome 

        //x must divide all abs(a[i] - a[n-i-1])
        int ans=0;
        for(int i = 0;i<n/2;i++)
        {
            ans = __gcd(ans,abs(a[i]-a[n-i-1]));
        }
        cout<<ans<<'\n';    
    }
    return 0;
}