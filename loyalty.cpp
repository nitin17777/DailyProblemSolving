#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Bit dicy about this solution
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,X;
        cin>>n>>X;

        // int total = 0;
        vector<int>a(n);
        for(auto&x:a)
        {
            cin>>x;
        }

        // X = loyalty factor
        //Loyalty level = s/X , s=total cost of purchased items so far
        
        //If loyalty level increases as a result of any purchase-> bonus 'p' is earned

        //find max number of bonus point we can earn by doing so 

        // int currScore = 0;
        sort(a.begin(),a.end());

        //if currScore + x < X -> take from left 
        // else take from right

        // vector<int>order;
        // int bonus = 0;
        // while(left<=right)
        // {
        //     if(currScore + a[right] < X)
        //     {
        //         currScore += a[left];
        //         left++;
        //     }
        //     else 
        //     {
        //         currScore += a[right];
        //         bonus+=a[right];
        //         right--;
        //     }
        // }
        // cout<<bonus<<'\n';

        // int k = total/X;

        // ll ans = 0;
        // for(int i =n-k;i<n;i++)ans+=a[i];
        // cout<<ans<<'\n';

        // cout<<'\n';    


        int l = 0,r=n-1;
        ll sum = 0,bonus=0;

        vector<ll>order;

        while(l<=r)
        {
            if(sum/X <(sum+a[r]) / X)
            {
                sum+=a[r];
                bonus+=a[r];
                order.push_back(a[r]);
                r--;
            }

            else
            {
                sum+=a[l];
                order.push_back(a[l]);
                l++;
            }
        }

        cout<<bonus<<'\n';

        for(auto&x:order)cout<<x<<" ";

        cout<<'\n';
    }
    return 0;
}