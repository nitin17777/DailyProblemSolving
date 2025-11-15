#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string n;
        cin >> n;
        int cnt = 0;

        for (int i = 0; i < n.size(); i++)
        {
            if (n[i] == '1')
                cnt++;
        }

        cout << cnt << endl;
    }
    return 0;
}
