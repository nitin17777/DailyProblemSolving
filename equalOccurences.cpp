#include <bits/stdc++.h>
using namespace std;

int longest(vector<int> &arr)
{
    // we have to find the length of longest balanced substring

    // balanced substring is one with all elements having same frequency

    // find frequency of all elements ->

    // we need to make all frequencies while maximising longest length of the substring

    int n = arr.size();
    unordered_map<int, int> freq;
    for (auto &num : arr)
    {
        freq[num]++;
    }

    vector<int> frequencies;
    for (auto &p : freq)
    {
        frequencies.push_back(p.second);
    }
    int maxLen = 0;

    // trying and checking whichever element will be able to contiribute in our final substring  ,like how many distinct element with frequency greater than 1 etc ...
    for (int targetFreq = 1; targetFreq <= arr.size(); targetFreq++)
    {
        int distinctCount = 0;

        // checking whichever element will be able to contiribute in our final substring
        for (int f : frequencies)
        {
            if (f >= targetFreq)
            {
                distinctCount++;
            }
        }
        int length = distinctCount * targetFreq;
        maxLen = max(maxLen, length);
    }
    return maxLen;
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

        cout << longest(arr) << endl;
    }
    return 0;
}