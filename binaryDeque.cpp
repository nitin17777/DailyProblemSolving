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
        int n,s;
        cin>>n>>s;

        int total = 0;
        vector<int>a(n);
        for(auto&x:a)
        {
            cin>>x;
            if(x==1)total++;
        }

        int target = total-s;

        //We have to delete target number of 1s form given array, now determine minimum number of operations required to do so

        if(target<0)
        {
            cout<<-1<<'\n';
            continue;
        }

        if(target==0)
        {
            cout<<0<<'\n';
            continue;
        }


        //While removing, as soon as ones count become zero -> we will have our answer ready

        //Or find the longest subarray containing exactly 's' ones
        // so min ops = n-longestSubLength

        int left = 0;
        int ones = 0;
        int maxLen = -1;

        for(int right=0;right<n;right++)
        {
            ones+=a[right];

            //When more than required number of ones are there
            while(ones>s)
            {
                ones -= a[left];
                left++;
            }

            if(ones == s)
            {
                maxLen = max(maxLen,right-left+1);
            }
        }

        cout<<n-maxLen<<'\n';
        
    
    }

    return 0;
}