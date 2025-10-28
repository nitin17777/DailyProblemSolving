#include <bits/stdc++.h>
using namespace std;

int maxSlices(int n)
{
    int ans = 0;

    while (n > 2)
    {
        ans += n / 3;

        n = n / 3 + n % 3;
    }
    return ans;
}

/*
int maxSlices(int n)
{
    // if atmost 2 slices are remaining ,alex eats all

    // otherwise , let m>=3 , Hao splits them into three groups of sizes m1 m2 m3 :  m= m1+m2+m3  : 1 <= m1 <= m2 <= m3

    // Hao eats m1,Alex eats m2 and m3 are carried to nenxt day

    // Determine max total slice Hao can eat

    if (n <= 2)
        return 0;
    int totalHao = 0;

    while (n > 2)
    {
        int m1 = n / 3; // Hao

        int rem = n % 3;

        int m2 = n / 3;
        int m3 = n / 3;

        if (rem == 1) // if only 1 is remainder , increase m3 only
            m3++;

        else if (rem == 2) // n%3 can only be 0,1,2
        {
            m2++;
            m3++;
        }

        totalHao += m1;
        n = m3;
    }
    return totalHao;
}*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << maxSlices(n) << endl;
    }
    return 0;
}