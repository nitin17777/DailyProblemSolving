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

        /*
        
        ith segment starts at li and ends at ri 

        Starts the level at coordinate 0 and in one move they can move to any point that is within distance of no more than k and after that move player must land at point within the ith segment

        And similarly after the nth segment they must be inside the nth segment

        Level is considered complete when he reaches the nth segement

        So we nedd to determine the min value of k so that he can complete the game
        */
        vector<pair<ll,ll>>seg(n);
        for(int i=0;i<n;i++)cin>>seg[i].first >> seg[i].second;

        //Determines if we can move k distance, can we complete all segments or not

        auto check = [&](ll k)
        {
            ll left=0,right = 0;

            for(auto[l,r]:seg)
            {
                // Range we can move upto 
                left -= k;
                right += k;

                left = max(left,l);
                right = min(right,r);

                if(left>right)return false;
            }
            return true;
        };

        ll l = -1;
        ll r = 1e9;

        while(r-l > 1)
        {
            ll mid = (l+r)/2;

            if(check(mid))r = mid;
            else l = mid;
        }
        cout<< r <<'\n';
    }
    return 0;
}