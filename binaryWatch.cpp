#include <bits/stdc++.h>
using namespace std;

vector<string> readBinaryWatch(int turnedOn)
{
    vector<string> result;

    for (int hour = 0; hour < 12; hour++)
    {
        for (int minute = 0; minute < 60; minute++)
        {

            // Count total set bits in hour and minute
            int totalBits = __builtin_popcount(hour) + __builtin_popcount(minute);

            if (totalBits == turnedOn)
            {
                string time = to_string(hour) + ":";

                // Ensure minute is always 2 digits
                if (minute < 10)
                    time += "0";

                time += to_string(minute);

                result.push_back(time);
            }
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> ans = readBinaryWatch(1);

    for (auto &x : ans)
        cout << x << endl;
    return 0;
}