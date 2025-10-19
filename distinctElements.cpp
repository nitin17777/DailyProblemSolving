#include <bits/stdc++.h>

using namespace std;

int distinctEle(vector<int> &arr)
{
    unordered_set<int> nums;
    for (auto num : arr)
    {
        nums.insert(num);
    }

    return nums.size();
}

vector<int> possible(vector<int> &arr)
{
    // f(c) = number of distinct elements in c

    // construct array b of n elements such that bi = f(a[1,i]) + f(a[2,i])+ ....

    // we have to find array 'a'
}

int main()
{
    vector<int> arr = {1, 3, 5};
    vector<int> ans = possible(arr);

    for (auto &an : ans)
    {
        cout << an << " ";
    }
    cout << endl;

    return 0;
}
