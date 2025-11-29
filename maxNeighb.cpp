#include <bits/stdc++.h>
using namespace std;

int cost(int n)
{

    /*
    A square matric of n*n size would be there

    //we have to find the max cost among all cells in the grid



    Right => +1
    Left => -1
    up = -4
    down = +4



    */
    int maxi = 0;
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
        cout << cost(n) << endl;
    }
    return 0;
}