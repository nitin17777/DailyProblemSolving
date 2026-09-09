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
        cin >> n;
        
        vector<int> vec(n); for (auto &x: vec) cin >> x;
        
        int mod_4[] {0, 0, 0, 0};
        for (auto &x: vec) mod_4[x%4]++;
        cout << max({mod_4[0], mod_4[2], mod_4[1] + mod_4[3]}) << "\n";
    }

    return 0;
}