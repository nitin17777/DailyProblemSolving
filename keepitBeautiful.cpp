#include <bits/stdc++.h>
using namespace std;

string solve(vector<int> &arr)
{

    int n = arr.size();
    /*

    Append the given query qi if the array remains beautiful after appending, otherwise do nothing

    And after each query report whether appended or not
    */

    //The element we insert must be either greater than last digit or smaller than the first digit

    vector<int>a;
    int cnt = 0;
    string ans = "";//No problem with 1st two char ig

    for(int x:arr)
    {
        int newCnt = cnt;

        if(!a.empty() && a.back() >x)newCnt++;

        if (newCnt == 0 || (newCnt == 1 && x <= a[0]))
        {
            a.push_back(x);
            cnt = newCnt;
            ans += '1';
        }

        else ans+='0';
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a) << endl;
    }
    return 0;
}