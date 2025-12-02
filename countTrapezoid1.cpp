#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 10000000007LL;

int countTrapezoids(vector<vector<int>> &points)
{
    // points[i] = coordinates of i on cartesian plane

    // return number of unique trapezoids that can be formed by choosing any 4 disticnt points

    // Trapezoid => atleast two sides are parallel to x axis

    /*

    Algo: Count all points with same y coordinates ,means how many points are there in each coordinate group

    then nC2 * mC2
    */

    unordered_map<int, int> freq;
    for (auto &p : points)
    {
        freq[p[1]]++;
    }

    ll sumh = 0, sumh2 = 0; // sumh stores : h1 + h2.... and sumh2 stores: h1^2 + h2^2 ....

    vector<ll> h;
    for (auto &[y, k] : freq)
    {
        if (k >= 2)
        {

            ll h = 1LL * k * (k - 1) / 2;
            h %= MOD;

            // for handling larger inputs: sigma hi * hj = ((sigma h1) ^2 - sigma hi^2)/ 2
            sumh = (sumh + h) % MOD;
            sumh2 = (sumh2 + (h * h) % MOD) % MOD;

            // h.push_back(1LL * k *(k-1)/2);
        }
    }

    ll total = (sumh * sumh) % MOD;
    total = (total - sumh2 + MOD) % MOD;

    // multiply by modular inverse of 2
    ll inv2 = (MOD + 1) / 2; // MOD is odd prime
    total = (total * inv2) % MOD;

    return total;

    /* Will get  TLE if used loop like this

    ll ans = 0;
    for(int i = 0; i < h.size(); i++)
    {
        for(int j = i+1; j < h.size(); j++)
        {
            ans = (ans + h[i] * h[j] %MOD)%MOD;
        }
    }

    return ans;
    */

    // when only 1 type of y coordinate is there
    //  if(freq.size() <=1)return 0;

    // vector<int>final;
    // for(auto & num : freq)
    // {
    //     int k = num.second;
    //     if(k < 2)continue;

    //     else final.push_back((k*(k-1))/2);
    // }

    // int ans = 1;
    // for(auto nu :final)
    // {
    //     if(nu == 0)continue;
    //     else ans*=nu;
    // }

    // return ans % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> points = {{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}};
    cout << countTrapezoids(points) << endl;

    return 0;
}