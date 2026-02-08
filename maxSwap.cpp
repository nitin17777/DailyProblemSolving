#include <bits/stdc++.h>
using namespace std;

int maximumSwap(int num)
{
    // from right, swap the largest number from right with the current digit

    string str = to_string(num);
    int n = str.size();

    vector<int> last(10, -1);
    // Storing the last occurence of this digit first
    for (int i = 0; i < n; i++)
    {
        last[str[i] - '0'] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int d = 9; d > str[i] - '0'; d--)
        {
            if (last[d] > i)
            {
                swap(str[i], str[last[d]]);
                return stoi(str);
            }
        }
    }
    return num;
}

/*
int maximumSwap(int num)
{
    // Swap the largest didgit with the first

    string str = to_string(num);
    int n = str.size();

    // string srtd = str;
    // sort(srtd.begin(), srtd.end());

    pair<int, int> maxi = {0, str[0]};

    for (int i = 1; i < n; i++)
    {
        if (str[i] > maxi.second)
        {
            maxi = {i, str[i]};
        }
    }

    if (str[0] == maxi.second)
        return num;

    for (int i = 0; i < n; i++)
    {
        if (str[i] != maxi.second)
        {
            swap(str[i], str[maxi.first]);
            break;
        }
    }
    int ans = stoi(str);
    return ans;
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num = 2736;
    cout << maximumSwap(num) << endl;

    return 0;
}