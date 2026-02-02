#include <bits/stdc++.h>
using namespace std;

/*vector<int>solve()
{



    Lottery winnner on day i was not allowed to participate in lottery days from i+1 to m

    Find any possible list of lottery  winners from days 1 to m

    else return -1



    //Look for the number which is not coming after it appeared once

    //Jiski presence us case ke aage nhi hogi use ans m push krdo lese return -1 ,agr koi aik bhi ans nhi deta hai to



} */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    const int MAX = 50000;
    vector<int> last(MAX + 1);

    while (t--)
    {
        int m;
        cin >> m;

        vector<vector<int>> days(m);
        for (int day = 0; day < m; day++)
        {
            int n;
            cin >> n;
            days[day].resize(n);

            for (int j = 0; j < n; j++)
            {
                cin >> days[day][j];
                last[days[day][j]] = day; // last occurence
            }
        }

        vector<int> ans(m, -1);

        // Now we will check for every element that if this day is the last day it occured, if yes- > simply push it to the array

        for (int day = 0; day < m; day++)
        {
            for (int x : days[day])
            {
                if (last[x] == day)
                {
                    ans[day] = x;
                    break;
                }
            }

            if (ans[day] == -1)
            {
                cout << -1 << endl;
                goto next_test; // Used to directly go to the text : "next_test"
            }
        }

        for (int x : ans)
            cout << x << " ";

        cout << endl;

    next_test:;
    }
    return 0;
}