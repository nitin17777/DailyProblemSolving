#include<bits/stdc++.h>
#define int long long
using namespace std;


int solve(vector<long long>&a,int n)
{
    //output the max value of (ak . a1) + (ak . a2)+ ...(ak . an)

    //So firstly we need to find the value with which XOR would be greatest 
    vector<long long>cnt(60,0);
    for(int i = 0;i<n;i++)
    {
        for(int bit =0;bit<60;bit++)
        {
            //Checks if the bit th bit of a[i] 1 or not, if yes->increase the count
            if((a[i] >> bit) & 1)cnt[bit]++;
        }
    }

    int ans = 0;

    //trying every element as ak now
    for(int i = 0;i<n;i++)
    {
        int totalSum = 0;

        for(int bit = 0; bit<60; bit++)
        {
            //checking if the current element has that bit set or not
            bool isSet = (a[i] >> bit) & 1;

            if(isSet)
            {
                //if bit is 1 -> XOR gives 1 only with numbers having bit 0
                int zeroCount = n - cnt[bit];
                totalSum += zeroCount * (1LL << bit);
            }

            else 
            {
                //if bit is 0 -> XOR gives 1 only with numbers having bit 1
                int oneCount = cnt[bit];
                totalSum += oneCount * (1LL << bit);
            }
        }
        ans = max(ans,totalSum);
    }
    return ans;
    
}

      
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    
    }

    return 0;
}