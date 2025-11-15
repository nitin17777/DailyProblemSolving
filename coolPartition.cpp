#include <bits/stdc++.h>
using namespace std;

// was able to build the complete though process behind this problem, but my implementation somehow failed for hidden test cases,though learnt a new apporoach :)

void solve()
{

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> distinct(n); // distinct[i] = number of distinct elements in prefix v[0....i]

    vector<int> freq(n + 1); // used to count the number of occurenece

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        freq[v[i]]++;
        if (freq[v[i]] == 1) // if elemnet has appeared for the first time
            distinct[i] = 1;
        distinct[i] += (i ? distinct[i - 1] : 0);
    }

    fill(freq.begin(), freq.end(), 0);

    int ans = 0;
    int end = n - 1;

    total = 0;

    // we will be proceesing form right to left to form required segments

    for (int i = n - 1; i >= 0; i--)
    {
        freq[v[i]]++; // current element in current suffix

        if (freq[v[i]] == 1)
            total++; // IF it appeared for the first time,increase the count of distinct elements in our segement

        if (total == distinct[end]) // suffix distinct == prefix distinct
        {
            ans++; // we found one valid segment

            // now resetting the frequency of current segment
            for (int j = i; j <= end; j++)
            {
                freq[v[j]] = 0;
            }

            end = i - 1; // shifting the boundary towards left
            total = 0;   // also reset the distinct count for next segment
        }
    }
    cout << ans << endl;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}

// Absolutely correct approach , but TLE

// int checkk(vector<int> &arr, int l, int r)
// {
//     set<int> st;

//     for (int i = 0; i <= r; i++)
//         st.insert(arr[i]);
//     int req = st.size();

//     set<int> seen;

//     while (r >= l)
//     {
//         seen.insert(arr[r]);
//         r--;

//         if ((int)seen.size() == req)
//             return r + 1;
//     }
//     return l;
// }

// int maxSegments(vector<int> &arr)
// {
//     /*
//     A segment is cool if after partition ,all elements in bj also appear in bj+1

//     //Find the max number of segements that make a cool partition

//     //The last segment of given array must contain all the distinct elments that are present in our array

//     //And similarly for other segemnts also,they must conntain all previously visited elements

//     */

//     // so first segment would be from n-1 to the index at which we are able to find all elements

//     // Now similar type of loop is required for it's prevous segment also

//     int l = 0, r = arr.size() - 1;

//     int cnt = 0;

//     while (r >= 0)
//     {

//         int idx = checkk(arr, l, r); // index where we got all elements for all elements;

//         // now check for index where diff.size() -1 elements are found

//         r = idx - 1;
//         cnt++;
//     }
//     return cnt;
// }