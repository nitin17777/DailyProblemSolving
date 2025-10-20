#include <bits/stdc++.h>
using namespace std;

bool prevEle(string s, int idx, int k)
{
    // check if anyg of the prev k-1 elements are 1 or not
    int start = max(0, idx - (k - 1));

    for (int i = start; i < idx; i++)
    {
        if (s[i] == '1')
            return true;
    }
    return false;
}

int minPos(string s, int k)
{
    // choose some positions in 's' t protect

    // Then for each i in increasing order,he can set si to 0 if :
    //(si == 1 )&& (si is not protected) && (previous k-1 elements does not contain 1)

    // Determine number of positions to protect so as to force to leave the string s unchanged
    int n = s.size();
    int count = 0;

    if (s[0] == '1')
        count++; // precessing initial index
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1' && (!prevEle(s, i, k)))
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;
        cout << minPos(s, k) << endl;
    }

    return 0;
}
