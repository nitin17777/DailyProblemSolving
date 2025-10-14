#include <bits/stdc++.h>
using namespace std;

long long maximumTotalDamage(vector<int> &power)
{

    // each element represents the damage of the spell

    // if he can cast a spell with damage power[i], they can't cast any spell with damage power[i]-2, power[i]-1, power[i]+1,power[i]+2
}

int main()
{

    vector<int> power = {1, 1, 3, 4};
    cout << maximumTotalDamage(power) << endl;

    return 0;
}