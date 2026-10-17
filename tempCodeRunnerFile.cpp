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

        //ith flower has hi height 
        
        //for each i from 1 to n : if i==n  or hi > hi+1 -> value of hi changes to max(0,hi -1)


        //how many seconds will pass before height of all i becomes 0

        //Or we can say curr time 
        int ans = a[n-1];

        for(int i = n-2;i>=0;i--)
        {
            ans = max(ans+1, a[i]);
        }
        cout<<ans<<'\n';
    }

    return 0;
}