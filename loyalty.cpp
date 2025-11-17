#include <iostream>
#include <vector>

using namespace std;

vector<int> maxi(vector<int> &prices, int lf)
{
    int n = prices.size();
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, lf;
        cin >> n >> lf;

        vector<int> prices(n);
        for (auto x : prices)
            cin >> x;

        vector<int> ans = maxi(prices, lf);
        cout << ans.size();
        for (auto x : ans)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
