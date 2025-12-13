#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    /*
    Choose a continuous segment and paint them all white
    Return the min lenght of segments that needs to be painted white in order for all n cells to become white

    We just need to enclose the first and last B present in array

    //Find the first occurence of B from start and end and return (r-l+1)

    */
    int n = s.size();

    int i = 0;
    int j = n - 1;
    while (s[i] != 'B' && i <= n - 1)
        i++;

    while (s[j] != 'B' && j >= 0)
        j--;

    return j - i + 1;
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

        string s;
        cin >> s;

        cout << solve(s) << endl;
    }
    return 0;
}