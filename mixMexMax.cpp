#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int> &arr)
{
    // array a is good if and only if : mex(ai, a i+1, ai+2) = max(ai,ai+1,ai+2) - min(ai, a i+1, ai+2)

    // Case 1: If MEX == 0: Then all elements must be equal, because then only MAX == MIN

    // Case 2: IF MEX != 0: Then MIN == 0 and then MEX == MAX, but this is not possible because MEX can't be present in the sequence we have....So this case is not possible ....So we have only 1st condition remaining

    // So remove all -1 from given array and check if all remaining elements are equal and non zero
    int n = arr.size();

    set<int> s(arr.begin(), arr.end());

    s.erase(-1);

    if (s.size() <= 1 && !s.count(0))
        return true;

    else
        return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << ((canMake(arr)) ? "Yes" : "No") << endl;
    }
    return 0;
}
