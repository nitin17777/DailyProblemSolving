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

        for(auto & x:a)cin>>x;

        /*
        
        Number of indices i such that subarray : ai... ai+k with lenght k+1 has :
        multiplying by 2^i makes the subarray sorted


        We basially need to check : ai < 2ai+1 for each pair
        */

        vector<int>b;
        for(int i = 0;i<n-1;i++)
        {
            if(a[i] < 2*a[i+1])b.push_back(1);
            else b.push_back(0);
        }

        //We have constructed b succesfuly, now we check how many subarrays in array b are there of length k whose all elements are equal to 1

        int m = b.size();

        if(k>m)
        {
            cout<<0<<'\n';
            continue;
        }

        int ans = 0;
        int sum = 0;

        for(int i = 0;i<k;i++)sum+=b[i];

        if(sum == k)ans++;

        for(int i = k;i<m;i++)
        {
            sum-=b[i-k];
            sum+=b[i];

            if(sum == k)ans++;
        }
        cout<<ans<<'\n';
    }

    return 0;
}