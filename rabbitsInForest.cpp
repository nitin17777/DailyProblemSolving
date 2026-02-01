#include <bits/stdc++.h>
using namespace std;

int numRabbits(vector<int> &answers)
{

    int n = answers.size();
    unordered_map<int, int> freq;

    for (auto &x : answers)
        freq[x]++;

    int total = 0;

    for (auto &it : freq)
    {
        int x = it.first;    // The answer they are telling
        int cnt = it.second; // Number of rabbits saying yes

        // Since x rabbits + that rabbit of same group
        int groupsize = x + 1;

        int groups = (cnt + groupsize - 1) / groupsize;

        // Since each group contribute (x+1)rabbits => So total rabbits= groups * groupsize
        total += groups * groupsize;
    }

    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ans = {1, 1, 2};

    cout << numRabbits(ans) << endl;

    return 0;
}