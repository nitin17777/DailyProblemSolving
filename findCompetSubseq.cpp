#include <bits/stdc++.h>
using namespace std;

vector<int> mostCompetitive(vector<int> &nums, int k)
{
    int n = nums.size();

    // More competitive if in the first point of difference a has a smaller number than b

    int remove = n - k;

    vector<int> st;

    for (int num : nums)
    {
        while (!st.empty() && st.back() > num && remove > 0)
        {
            st.pop_back();
            remove--;
        }

        st.push_back(num);
    }
    st.resize(k);
    return st;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {3, 5, 2, 6};

    vector<int> ans = mostCompetitive(nums, 2);

    for (auto &an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}