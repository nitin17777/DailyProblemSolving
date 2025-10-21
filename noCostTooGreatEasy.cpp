#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
vector<vector<int>> primeFactors(MAX_N + 1);

void prePrimeFactors()
{
    for (int i = 2; i <= MAX_N; i++)
    {
        if (!primeFactors[i].empty())
            continue; // since it must have been already been marked

        for (int j = i; j <= MAX_N; j += i)
        {
            primeFactors[j].push_back(i);
        }
    }
}

int minCost(vector<int> &a, vector<int &> b)
{
    // Select an integr i (1<=i<=n) and increase ai by 1, this has cost of bi

    // Determine total cost to make it so that two integers i,j where 1<i<j<n and gcd(ai,aj) > 1

    // Here bi is 1 for all i
    int n = a.size();
    map<int, int> count;
    int ans = 2;
    for (int i = 0; i < n; i++)
    {
    }
}

int main()
{
    vector<int> a = {4, 8};
    vector<int> b = {1, 1};

    cout << minCost(a, b) << endl;

    return 0;
}
