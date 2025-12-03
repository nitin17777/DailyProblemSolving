#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Needed to Normalize slope so that slopes like 2/4 and -2/-4 become 1/2
pair<int, int> normalize(int dx, int dy)
{
    if (dx == 0)
        return {1, 0};
    if (dy == 0)
        return {0, 1};

    int g = __gcd(abs(dx), abs(dy));

    // Reducing fractions

    dy /= g;
    dx /= g;

    // normalising sign
    if (dx < 0)
    {
        dx = -dx;
        dy = -dy;
    }
    return {dy, dx};
}

int countTrapezoids(vector<vector<int>> &points)
{
    // check how many equal slopes are present

    int n = points.size();
    if (n < 4)
        return 0;

    // slopeMap -> List of segments with that slope

    unordered_map<ll, vector<pair<int, int>>> slopeMap;

    // Encoding pair<int,int>as a 64 bit key for hashmap

    auto encode = [&](pair<int, int> p)
    {
        // shifting dy and dx to positive range then combine
        return (ll)(p.first + 20000) << 32 | (p.second + 20000);
    };

    // Building all line segments and group them by slope
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dy = points[j][1] - points[i][1];
            int dx = points[j][0] - points[i][0];

            auto s = normalize(dx, dy);
            ll key = encode(s); // encoding slope as hash map key

            slopeMap[key].push_back({i, j}); // store this segment now
        }
    }

    ll ans = 0;

    // Now counting valid trapezoids for each slope group
    for (auto &entry : slopeMap)
    {
        auto &segments = entry.second;
        int k = segments.size();

        // Since we need atleast 2 segments with same slope to form trapezoid
        if (k < 2)
            continue;

        // Potential trapezoids
        ll totalPairs = 1LL * k * (k - 1) / 2;

        // But there are some points which can share smae point, we must remove them
        unordered_map<int, int> cnt;
        for (auto &seg : segments)
        {
            cnt[seg.first]++;
            cnt[seg.second]++;
        }

        ll bad = 0;
        for (auto &p : cnt)
        {
            int c = p.second;
            if (c >= 2)
            {
                bad += 1LL * c * (c - 1) / 2;
            }
        }
        // Valid trapezoids = total pairs - overlapping pairs
        ans += totalPairs - bad;
    }
    return ans;
}
/*
int countTrapezoids(vector<vector<int>>& points)
{
    //We have to return the number of unique trapezoids using any 4 given points

    set<pair<int,int>>s;


    int count = 0;
    for(auto &p : points)
    {
        //check if element at 0th index  == 1st index and 1st index == 0th index of any given point. And number of pair fulfilling this would be our answer
        int a = p[0];
        int b = p[1];

        if(s.count({b,a}))count++;

        s.insert({a,b});
    }
    return count;
}

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> points = {{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}};

    cout << countTrapezoids(points) << endl;

    return 0;
}