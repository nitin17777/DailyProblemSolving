#include<bits/stdc++.h>
#define ll long long
using namespace std;

   
//CORRECT BUT NEED TO OPTIMISE IT BADLY
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin>>t;

//     while(t--)
//     {
//         ll k,x;
//         cin>>k>>x;

//         //Will be banned if we spam atleast x emotes successively

//         // Determine how many meesages can be sent before getting banned?

//         /*

//         .  1 
//         .. 3
//         ... 6
//         .... 10
//         ... 13
//         .. 15
//         . 16
        
//         */
//        vector<ll>arr(2*k,0);

//        bool found = false;
//        arr[0] = 1;
//        if(arr[0] >= x)
//         {
//             cout << 1 << '\n';
//             continue;
//         }


//        for(int i =1;i<k;i++)
//        {
//             arr[i] = i+1+arr[i-1];

//             if(arr[i] >= x)
//             {
//                 cout<<i+1<<'\n';
//                 found = true;
//                 break;
                
//             }
//        }

//        if(found)continue;

//        for(int i=k;i<2*k-1;i++)
//        {
//             arr[i] = (2*k-i-1)+arr[i-1];
//             if(arr[i] >= x)
//             {
//                 cout<<i+1<<'\n';
//                 found = true;
//                 break;
//             }
//        }

//        if(!found)cout<<arr[2*k-1]<<'\n';
//     }

//     return 0;
// }


//Returns number of emotes sent if 'mid' messages are sent till now
ll calc(ll mid,ll k)
{
    if(mid<=k)
    {
        return mid*(mid+1)/2;
    }

    ll ans = k*(k+1)/2;

    ll extra = mid-k;
    ans+=extra*k;
    ans-=extra*(extra+1)/2;
    return ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll k,x;
        cin>>k>>x;

        ll low = 0,high = 2*k-1,ans = 2*k-1;

        while(low<=high)
        {
            ll mid = (low+high)/2;

            if(calc(mid,k) >= x)
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        cout<<ans<<'\n';
    }

}

