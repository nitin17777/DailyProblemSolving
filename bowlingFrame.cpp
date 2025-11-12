#include <bits/stdc++.h>
#define int long long
using namespace std;

int canBuild(int k, int w, int b)
{
    /*
    color of pins on same row must be same
    //calculate the side length of lagest frame he can build from w and b

    if we want to build a frame of size k, we need atleast k(k+1)/2 pins
    or w+b >= k(k+1)/2 =>Then we can always do the construction


    And then one color must satisfy : max(w,b) >= k(k+1)/ 4
    */

    return w + b >= (k * (k + 1)) / 2;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int w, b;
        cin >> w >> b;

        int low = 0, high = 1e6, ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canBuild(mid, w, b))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
