#include<bits/stdc++.h>
#define ll long long
using namespace std;

      

//Full brute force approach but eliminared most of the unneccessary searches
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
        //find number of pairs: ai * aj = i+j

        //since i+j <= 2n => So a[i] * a[j] can atmost go tilll 2n

        vector<int>a(n+1);
        vector<int>pos(2*n+1);

        for(int i = 1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]] = i;
        }

        int ans = 0;


        /*

        ai * aj <= 2n

        if ai is fixed -> aj = 2*n / a[i];
        
        */


        for(int i =1;i<=n;i++)
        {
            for(int x=1;x<= 2*n / a[i]; x++)
            {
                int j = pos[x];

                if(j>i && a[i]*x == i+j)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}