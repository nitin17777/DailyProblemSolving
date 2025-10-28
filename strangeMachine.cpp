#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> time(string s, vector<ll> queries)
{
    int n = s.size();
    int q = queries.size();

    int A = count(s.begin(), s.end(), 'A');
    int B = count(s.begin(), s.end(), 'B');

    // Compressig the string into sequences like AAABBBA" → [('A',3), ('B',3), ('A',1)]

    vector<pair<char, int>> seq;
    char last = s[0];
    int curr = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == last)
            curr++;

        else
        {
            seq.push_back({last, curr});
            curr = 1;
            last = s[i];
        }
    }
    if (curr > 0)
        seq.push_back({last, curr}); // for last ones

    // Step 2: Simulating the proces for each query
    vector<ll> ans;

    // since if no B will be there, A will simply decrease the values by 1 continuously
    if (B == 0)
    {
        for (auto val : queries)
            ans.push_back(val);
    }

    else
    {
        // if B's are there , division must happen
        for (int i = 0; i < q; i++)
        {
            long long x = queries[i];
            long long total = 0; // for total time taken

            while (x > 0)
            {
                for (auto &j : seq)
                {
                    if (x == 0)
                        break; // since, then number would have been fully reduced to 0

                    if (j.first == 'A')
                    {
                        long long mn = min((ll)j.second, x);
                        total += mn;
                        x -= mn;
                    }

                    else
                    {
                        // In B => divide x by 2 repeatedly
                        if (x == 0)
                            break;

                        // count how many divisions we can do before x becomes 0
                        ll temp = x, p = 0;
                        while (temp)
                        {
                            temp /= 2;
                            p++;
                        }

                        ll mn = min((ll)j.second, p);
                        total += mn;

                        x /= (1LL << mn);
                    }
                }
            }
            ans.push_back(total);
        }
    }
    return ans;
}

/*
vector<int> time(string s, vector<int> queries)
{
    int n = queries.size();

    // A => Decrease x by 1
    // B => Replace x with x/2


    // we put each num of query starting from given machine, and move it to B and this process continues till that number becomes 0. Each move takes 1 second, we need to find total seconds required to solve all the queries

    int totalTime = 0;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int x = queries[i];

        while (x > 0)
        {
            for (auto ch : s)
            {

                if (x == 0)
                    break;

                if (ch == 'A')
                    x -= 1;

                else if (ch == 'B')
                {
                    x /= 2;
                }
                totalTime++;
            }
        }
        ans.push_back(totalTime);
        totalTime = 0;
    }
    return ans;
}*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<ll> queries(q);
        for (int i = 0; i < q; i++)
        {
            cin >> queries[i];
        }
        vector<ll> ans = time(s, queries);

        for (auto an : ans)
        {
            cout << an << endl;
        }
    }
    return 0;
}