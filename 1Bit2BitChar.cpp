#include <bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int> &bits)
{

    // Just need to check if last 0 is paired with previous 1 or is just left stand alone

    int n = bits.size();

    int i = 0;

    while (i < n - 1)
    {
        if (bits[i] == 1)
            i += 2;

        else
            i++;
    }

    return i == n - 1;
}

int main()
{
    vector<int> bits = {1, 0, 0};
    cout << (isOneBitCharacter(bits) ? "true" : "false") << endl;
    return 0;
}
