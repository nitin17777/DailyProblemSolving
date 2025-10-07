#include <bits/stdc++.h>
using namespace std;

vector<int> avoidFlood(vector<int> &rains)
{
    // when it rains in the nth lake the nth lake becomes full of water,and if it rains over the nth lake , the nth lake becomes full of water and there will be flood ==> and we have to avoid flood in any lake

    // rains[i] >0 => there willl be rain over the rain[i] lake

    // rains[i] ==0 ==>np rains this day and we can choose one lake and can dry it

    // ans[i] == - 1 if rains[i]>0

    int n = rains.size();
    vector<int> ans(n, 1);

    // to keep track of when each lake was last filled
    unordered_map<int, int> full;

    // to store the indices of days when rains[i] == 0

    set<int> dryDays;

    for (int i = 0; i < n; i++)
    {
        int lake = rains[i];

        // if it's a dry day
        if (lake == 0)
        {
            dryDays.insert(i);
        }
        else
        {
            ans[i] = -1; // raining day

            // checking if this current lake was already filled or not
            if (full.count(lake))
            {
                // we need to find a dry day after the last time this lake was filled
                auto it = dryDays.lower_bound(full[lake]);

                // if no dry day is found
                if (it == dryDays.end())
                {
                    return {};
                }
                ans[*it] = lake;

                dryDays.erase(it);
            }
            full[lake] = i;
        }
    }
    return ans;
}

int main()
{
    vector<int> rains = {1, 2, 3, 4};

    vector<int> ans = avoidFlood(rains);

    for (auto &an : ans)
    {
        cout << an << endl;
    }

    return 0;
}
