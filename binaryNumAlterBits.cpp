#include <bits/stdc++.h>
using namespace std;

bool hasAlternatingBits(int n)
{
    unsigned int x = n ^ (n >> 1); // Shifting all the bits and taking XOR as XOR gives 0 when bits are same

    // If alternating -> Their AND = 0
    return (x & (x + 1)) == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << (hasAlternatingBits(5) ? "True" : "No") << endl;
    return 0;
}