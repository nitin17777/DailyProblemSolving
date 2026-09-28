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

        vector<ll>a(n+1);
        for(int i = 1;i<=n;i++)cin>>a[i];
        /*

        While array has atleast k elements -> we need to perform one of the following types of operations

        1->Remove ak and add it's value to your score 
        2-> Remove am-k+1 (kth value form last) and add its value to score, m=length of a before this operation

        Determine max possible score that can be obtained
        */

        ll ans = 0;


        //For a specific index i -> We are forced to delete exactly one element either from last or form first, so we should always go for the bigger one

        if(2*k <= n)
        {
            //Mids 
            for(int i=k;i<=n-k+1;i++)ans+=a[i];

            int l = 1,r=n;
            
            while(l<k)
            {
                ans+=max(a[l],a[r]);
                l++;
                r--;
            }
        }

        else
        {
            int l = 1,r=n;

            while(l<=n-k+1)
            {
                ans+=max(a[l],a[r]);
                l++;
                r--;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}