#include <bits/stdc++.h>
using namespace std;

// bool isInc(vector<int>&a)
// {
//     for(int i = 0;i<a.size();i++)
//     {
//         if(a[i-1] < a[i])return true;
//     }
// }

// bool isDec(vector<int>&a)
// {
//     for(int i = 0;i<a.size();i++)
//     {
//         if(a[i-1] > a[i])return true;
//     }
// }

bool isTrionic(vector<int> &nums)
{
    int n = nums.size();

    if (n < 4)
        return false;

    // increasing
    int i = 1;
    while (nums[i] > nums[i - 1])
        i++;
    if (i == 1 || i == n)
        return false; // Means it never happened or happedned forever

    // Now we got the point till first increment

    // Decreasing
    int j = i;
    while (j < n && nums[j] < nums[j - 1])
        j++;
    {
        if (j == i || j == n)
            return false;
    }

    // Increasing
    int k = j;
    while (k < n && nums[k] > nums[k - 1])
        k++;

    return k == n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {1, 3, 5, 4, 2, 6};
    cout << (isTrionic(a) ? "True" : "False") << endl;
    return 0;
}