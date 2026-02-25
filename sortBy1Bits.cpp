#include <bits/stdc++.h>
using namespace std;

// More optimised

vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), [](int a, int b)
         {

        int cntA = __builtin_popcount(a);
        int cntB = __builtin_popcount(b);

        if(cntA == cntB)return a<b;

        return cntA<cntB; });

    return arr;
}

// vector<int> sortByBits(vector<int>& arr)
// {
//     int n = arr.size();
//     vector<pair<int,int>>mp;

//     for(auto&x:arr)
//     {
//         int cnt = __builtin_popcount(x);
//         mp.push_back({x,cnt});
//     }

//     sort(mp.begin(),mp.end(), [](auto&a,auto& b)
//     {
//         if(a.second == b.second)return a.first < b.first;//tie breaker

//         return a.second < b.second;
//     });

//     //Sort by the number of 1's presnt in their binary form

//     for(int i = 0;i<n;i++)
//     {
//         arr[i] = mp[i].first;
//     }
//     return arr;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = sortByBits(a);
    for (auto &x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}