#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (n % 2 != 0)
            cout << 0 << endl;

        else
        {
            int ans = (n / 4) + 1;
            cout << ans << endl;
        }
    }
    return 0;
}
