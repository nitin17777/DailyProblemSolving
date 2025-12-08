#include <bits/stdc++.h>
using namespace std;

int countTriples(int n)
{

    // return the square triplets

    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int root = (i * i) + (j * j);
            int k = sqrt(root);

            if (k * k == root && k <= n)
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << countTriples(5) << endl;

    return 0;
}
