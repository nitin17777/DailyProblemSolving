#include <bits/stdc++.h>
using namespace std;
#define int long long

int awesome(vector<int> &a, int k)
{

    int n = a.size();

    vector<int> cnt(n + 1); // to count frequency of each element in given array

    for (int i = 0; i < n; i++)
    {
        cnt[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        // because we won't be able ot
        if (cnt[i] % k != 0)
            return 0;

        else
            cnt[i] /= k;
    }

    int res = 0;
    vector<int> ct(n + 1); // to trackk current subarray count

    for (int l = 0, r = 0; r >= l and r < n; r++)
    {
        ct[a[r]]++;

        // so that in this subarray count of that element does not go beyond total count of that element
        while (ct[a[r]] > cnt[a[r]])
        {
            ct[a[l]]--;
            l++;
        }
        res += r - l + 1;
    }
    return res;
}

/*
int awesome(vector<int>&arr,int k)
{
    // If l <= i <=r, he places ai in multiset 1,otherwise he places ai into any multiset he wants which can even be multiset 1

    //Subarray a[l,r] is awesome if there is some way for him to place elements such that for every value v, all multisets contain same number of elements with value

    //He wants to make all multisets contain the exact same elements

    //Return number of awesome subarrays
    int n = arr.size();


    unordered_map<int,int>freq;
    for(auto x: arr)freq[x]++;


    unordered_map<int,int>maxAllowed;
    for(auto&x: freq)
    {
        maxAllowed[x.first] = x.second / k;
    }

    long long ans = 0;
    unordered_map<int,int>cnt;

    int r = 0;

    for(int l = 0;l<n;l++)
    {
        while(r<n)
        {
            int v = arr[r];

            if(cnt[v] == maxAllowed[v])break;

            cnt[v]++;
            r++;
        }

        ans+=(r-l);
        cnt[arr[l]]--;
    }
    return ans;
}
*/

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (auto &x : arr)
            cin >> x;

        cout << awesome(arr, k) << endl;
    }

    return 0;
}
