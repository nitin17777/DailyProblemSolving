#include <bits/stdc++.h>
using namespace std;

int cnt(int n)
{
    int cn = 0;
    int sum = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int d1 = i, d2 = n / i;

            if (d1 == d2)
            {
                cn++; // if perfect square count once only
                sum += d1;
            }

            else
            {
                sum += d1 + d2;
                cn += 2;
            }

            if (cn > 4)
                return 0; // Stop as soon as we number of divisors exceed 4
        }
    }
    return (cn == 4) ? sum : 0;
}

int sumFourDivisors(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;

    // We have to return the sum of divisors present in array having exactly 4 divisors

    for (auto &x : nums)
    {
        ans += cnt(x);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {21, 4, 7};
    cout << sumFourDivisors(nums) << endl;

    return 0;
}