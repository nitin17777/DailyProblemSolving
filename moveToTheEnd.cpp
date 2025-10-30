#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> maxPossible(vector<ll> &arr)
{
    int n = arr.size();

    // choose an element from arr,move it to the end of the array

    // print the sum of k last elements of arr

    // now move the element back it's original position

    // k : {1,n}

    // for every k , we chose the element which should be moved so that value we print is max possible

    // calcualte the value for each k

    // it should be like : k = 1 ->largest

    vector<ll> temp = arr;
    sort(temp.rbegin(), temp.rend());

    // if last k elements does not include the greatest number of array,push the greatest one , if is present, push the second highest one and continue doing until k  = n

    // each time we will use k-1 elements from last + maximum remaining element

    // so answer would be : (Max value among first n-k+1 elements) + last k-1 elements

    vector<ll> pmax(n + 1);
    vector<ll> psum(n + 1);
    vector<ll> ans;

    // make two arrays: prefix max (pmax[i])=> max of first i elements
    //: (psum[i]) => sum of first i elements

    for (int j = 0; j < n; j++)
    {
        pmax[j + 1] = max(pmax[j], arr[j]);
        psum[j + 1] = psum[j] + arr[j];
    }

    for (int k = 1; k <= n; k++)
    {
        // pmax[n-k+1] =>max among the first n-k+1 elements
        // psum[n] - psum[n-k+1] =>sum of elements from n-k+1 to n
        ll an = pmax[n - k + 1] + (psum[n] - psum[n - k + 1]);
        ans.push_back(an);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<ll> ans = maxPossible(arr);
        for (auto &an : ans)
            cout << an << " ";
        cout << endl;
    }

    return 0;
}
