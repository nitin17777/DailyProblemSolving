#include <bits/stdc++.h>
using namespace std;

int minPartitions(string s)
{
    // Deci Binary: Normal binary number but without any leading zeros

    // Return min number of deci binary numbers to sum up to n

    int maxi = 0;
    for (char &c : s)
    {
        if (c - '0' > maxi)
            maxi = c - '0';
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << minPartitions("82734");

    return 0;
}