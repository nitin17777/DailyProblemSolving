#include <bits/stdc++.h>
using namespace std;

int longest(vector<int> &arr)
{
    // we hav eto find the length of longest balanced substring

    // balanced substring is one with all elements having same frequency

    // find frequency of all elements ->

    // we need to make all frequencies while maximising longest length of the substring

    int longest = 0;
    unordered_map<int, int> freq;
    for (auto &num : arr)
    {
        freq[num]++;
    }

    for (auto &nu : freq)
    {
    }
}

int main()
{
    vector<int> arr = {1, 1, 4, 4};

    cout << longest(arr) << endl;
    return 0;
}