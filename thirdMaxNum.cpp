#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector<int> &nums)
{

    // Use a set to remove duplicates automatically
    // BUT note: set stores numbers in ascending order
    set<int> st(nums.begin(), nums.end());

    // If we have fewer than 3 distinct elements,
    // the answer is the maximum element.
    if (st.size() < 3)
    {
        return *st.rbegin(); // largest element
    }

    // We need the 3rd maximum → iterate from the end
    auto it = st.rbegin(); // points to largest

    // Move iterator to the 3rd distinct largest element
    advance(it, 2); // move 2 steps back

    return *it;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}