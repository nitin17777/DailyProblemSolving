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

        string s;
        cin>>s;


        //Set s = first n positive integers : 1,2,3,..n
        //Choose any  k <= n and delete smallest multiple of k from S 

        //Determine min cost to transform S into T

        // S=12345678...n

        // 1 1 1 1 1 1 1
        // 1 1 0 1 0 0 1



        vector<bool>a(n+1);
        for(int i=1;i<=n;i++)a[i] = (s[i-1] == '1');
        

        ll ans = 0;

    
        int cost[n+1];
        
        for(int i = n;i>=1;i--)
        {
            for(int j = i;j<=n;j+=i)
            {
                if(a[j])break;
                
                cost[j] = i;
            }
        }

        for(int i = 1;i<=n;i++)
        {
            if(!a[i])ans += cost[i];
        }
        cout<<ans<<'\n';
    }

    return 0;
}