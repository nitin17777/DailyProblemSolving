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
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        for(auto &x:a)cin>>x;

        /*
        We can perform atleast k ops:

        For any index i, we are setting jth bit of ai to 1

        Return the max possible value of AND of the given array after atmost k ops

        Case 1: When n==k:

        Ans = 2^30 + another bit  powet that is common in other too



        //We will maintain a count of each bit from every element 
        */

        vector<int> freq(31,0);
        for(int x:a)
        {
            for(int bit=0;bit<=30;bit++)
            {
                if(x&(1<<bit))freq[bit]++;
            }
        }

        //Now we have count of every bit , from largest bit, check if we can set fulfil all bits with the help of given number of ops
        for(int i = 30;i>=0;i--)
        {
            int need = n-freq[i];

            if(need<=k)
            {
                k-=need;
                freq[i] = n;
            }           
        }

        int ans =0;
        for(int i =0;i<31;i++)
        {
            if(freq[i]==n)ans+=(1<<i);
        }
        cout<<ans<<'\n';
    }
    return 0;
}