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
    
        long long cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x == 0) cnt0++;
            else if (x == 1) cnt1++;
            else cnt2++;
        }

        long long pairs = min(cnt1, cnt2);
        long long rem = abs(cnt1 - cnt2);

        cout << cnt0 + pairs + rem / 3 << '\n';
    }

    return 0;
}