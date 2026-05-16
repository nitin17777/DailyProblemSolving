#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

     while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        int ans = 0;
        for (char c : {'A', 'B', 'C', 'D'}) {
            int cnt = count(s.begin(), s.end(), c);
            ans += min(n, cnt);
        }
        
        cout << ans << "\n";
    }

    return 0;
}