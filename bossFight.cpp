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
        
        //Max health of boss that can be defeated by our cards
        
        //If we use 2 same cards n next cards would become uselsss

        ll tSum = 0;
        map<int,int>freq;

        int maxFreq = 0;
        int majVal = 0;


        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;

            tSum+=x;
            freq[x]++;

            if(freq[x]>maxFreq)
            {
                maxFreq = freq[x];
                majVal = x;
            }
        }
        int others = n-maxFreq;

        int maxi = min(maxFreq,others+2);

        ll ans = (tSum - 1LL * maxFreq * majVal) + 1LL *maxi * majVal;

        cout<<ans<<'\n';
    }

    return 0;
}