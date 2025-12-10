#include <bits/stdc++.h>
using namespace std;

int countPermutations(vector<int> &complexity)
{
    int n = complexity.size();
    /*
    Password for ith computer is complexity[i]

    Password for computer labeled 0 is alredy decrypted and serves as root, annd all computers must be unlocked using it or another already unlocked computers

    We can decrypt password of computer i using passowrd for comp j : j<i && complexity[j] < complexity[i]

    Find number of perms of 1 - n-1,

    */

    int mn = *min_element(complexity.begin() + 1, complexity.end());
    if (mn <= complexity[0])
        return 0;

    int MOD = 1000000007;

    long long ans = 1;
    for (int i = 2; i < n; i++)
    {
        ans = (ans * i) % MOD;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> coms = {1, 2, 3};
    cout << countPermutations(coms) << endl;

    return 0;
}