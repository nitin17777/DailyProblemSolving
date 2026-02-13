#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &a)
{
    int n = a.size();

    /*
        Step 1: Store (value, original index)

        Why?
        Because after sorting, we will lose original positions.
        We need original index to place answer correctly.
    */
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], i});

    /*
        Step 2: Sort by shoe size (value)

        This groups students having same shoe size together.
    */
    sort(v.begin(), v.end());

    /*
        ans[i] = shoe assigned to student i
    */
    vector<int> ans(n);

    /*
        Step 3: Process equal-value groups
    */
    for (int i = 0; i < n;)
    {
        int j = i;

        /*
            Find range [i, j)
            containing students with same shoe size
        */
        while (j < n && v[j].first == v[i].first)
            j++;

        int len = j - i;

        /*
            If only one student has this shoe size,
            we cannot shuffle shoes because:
            - student must not get their own shoe
            - no other student has same size
            => impossible
        */
        if (len == 1)
            return {};

        /*
            Step 4: Rotate shoes inside group

            Idea:
            Give shoe of next student in group.
            Last student gets shoe of first student.

            This ensures:
            1) Nobody gets own shoe
            2) Shoe size remains same
        */
        for (int k = i; k < j; k++)
        {
            // cyclic next index inside group
            int next = (k + 1 == j ? i : k + 1);

            // assign shoe
            ans[v[k].second] = a[v[next].second];
        }

        // Move to next group
        i = j;
    }

    return ans;
}
