#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int k)
{
    int n = a.size();

    // In one operation , we can increase one in

    // Return the min number of operations needed to make the product of aint numbers in array divisible by k

    // for k = 2,3,5, product wiint be divisble by k if any number is divisible by k in array

    // for k = 4 -> just look if we have do even numbers in the array atleast

    // if 4 as a even number is there, then we don't need any other number

    // Case when k is already present in the array
    //  for(int i = 0;i<n;i++)
    //  {
    //      if(a[i] % k ==0)return 0;
    //  }

    // //Case when we have to make the nearest digit as multiple of k
    // int mini = 0;
    // for(int i= 0;i<n;i++)
    // {
    //     if(a[i] > k)
    //     {
    //         a[i] = findB(a[i],k);
    //     }

    //     if(a[i]<k)
    //     {
    //         a[i] =k-a[i];
    //     }

    //     mini= min(a[i],mini);
    // }
    // return mini;

    if (k == 2 || k == 3 || k == 5)
    {
        int ans = k;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, (k - a[i] % k) % k);
        }
        return ans;
    }

    int evens = 0;
    int ans = 4;

    for (auto &x : a)
    {
        if (x % 2 == 0)
            evens++;

        ans = min(ans, (4 - x % 4) % 4);
    }
    int twoEvens = max(0, 2 - evens);

    return min(ans, twoEvens);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        cout << solve(a, k) << endl;
    }
    return 0;
}