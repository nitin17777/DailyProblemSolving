#include <btis/stdc++.h>
using namespace std;

bool isPossible(vector<int> &s)
{
    /*
    Each second, each clock's time decreases by 1 ,and if any clock's time reaches 0 we lose

    //check if it is possible to run indefinitely!!

    */

    int n = nums.size();
    int maxi = *max_element(s.begin(), s.end());
    int mini = *min_element(s.begin(), s.end());

    if (maxi - mini <= 1)
        return false;

    return true;
}

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> s(n);
        for (auto &x : s)
            cin >> x;
        cout << (isPossible(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
