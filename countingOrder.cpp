#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;
      
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
        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;
        
        //Find number of ways to reorder a such that ai>bi

        int ans = 1;

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(int i = n-1;i>=0;i--)
        {
            //first element in a grearter than bi
            int pos = upper_bound(a.begin(),a.end(),b[i])-a.begin();

            //Number of elements greater than 
            ll greater = n-pos;

            //Elements already used 
            ll used = n-1-i;

            ll choices = greater-used;

            if(choices<=0)
            {
                ans=0;
                break;
            }
            ans = (ans*choices)%MOD;
        }
        cout<<ans<<'\n';
    }

    return 0;
}

// 2 5 6
// 1 3 3 