#include <bits/stdc++.h>
using namespace std;

int solve(string &s, char c)
{

    int n = s.size();
    s = s + s; // to work with circularity even

    int ans = 0;
    int lastG = -1;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (s[i] == 'g')
        {
            lastG = i;
        }

        if (i < n && s[i] == c)
        {
            ans = max(ans, lastG - i);
        }
    }
    return ans;

    // Light changes every n seconds

    // We can cross the road when the signal is green

    // So we basically have to find the max distance bw the char c and g

    // Means the distance bw char c and g should be maximised

    // int maxi = 0;
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = i+1;j<n;j++)
    //     {
    //         if(s[i] == c)
    //         {
    //             if(s[j] == 'g')
    //             {
    //                 int idx = j-i+1;
    //                 maxi = max(maxi,idx);
    //             }
    //         }
    //     }
    // }
    // return maxi;
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
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        cout << solve(s, c) << endl;
    }
    return 0;
}