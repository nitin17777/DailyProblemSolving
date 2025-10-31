#include <bits/stdc++.h>
using namespace std;

bool isValid(const vector<int> &cape, const vector<int> &a, int n)
{
    /*
    cape[i] = 0 → cape to LEFT (L)
    cape[i] = 1 → cape to RIGHT (R)
    */

    int visible = 1; // since wizard 1 is always visible

    // counting how many are visible at position 1 initially
    for (int i = 2; i <= n; i++)
    {
        if (cape[i] == 1)
            visible++; // since if cape is facing right , that means visibility from left is there
    }

    if (visible != a[1])
        return false; // if count by us is not equal to given count

    // now simulating movement from posi 1 to n
    for (int i = 1; i < n; i++)
    {
        // LL -> +1 visible
        // RR -> -1 visible
        // RL -> 0 change
        // LR -> 0 change

        // LL
        if (cape[i] == 0 && cape[i + 1] == 0)
            visible++;

        // RR
        else if (cape[i] == 1 && cape[i + 1] == 1)
            visible--;

        // in RL and LR , since change = 0 , so do nothing

        // check our given list with this visible count
        if (visible != a[i + 1])
            return false;
    }
    return true;
}
/*

ll arrangements(vector<ll>&arr)
{
    //each wizard has invisibility cape which can be worn from either left side or right side

    //wizard j wears his cape on left side and i >= j
    //wizard j wears his cape on left side and i <= j

    //wizard i is visible from position i

    //array a : a ith element is the number of wizards that harry saw from the position of wizard i

    //Determine how many of all the possible cape arranegement Harry could have seen are consistent with data recorded by list, modulo 676 767 677


    //whenver we move from position i to i+1,visibility of (1 to i-1) and (i+2 to n) stays the same

    //so we can conclude that visibility of wizards[i+1] and wizards may change


    //so a[i+1] - a[i] can be +1 , 0 , -1
}*/

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        bool possible = true;

        // arrays to track how many are visible in left and right from that position
        vector<int> capeStartL(n + 1);
        vector<int> capeStartR(n + 1);

        // looking both possibilities:
        capeStartL[1] = 0; // Left cape
        capeStartR[1] = 1; // right cape

        for (int i = 1; i < n; i++)
        {
            int diff = a[i + 1] - a[i]; // checking how visibility changes on moving from i to i+1

            if (diff > 1)
            { // impossible arrangement if visibility jumps by more than +1
                possible = false;
                break;
            }

            if (diff == 0)
            {
                // if no visibility change in bw => this case is of RL or LR

                // so i+1 must have cape opposite to i
                capeStartL[i + 1] = 1 - capeStartL[i];
                capeStartR[i + 1] = 1 - capeStartR[i];
            }

            else
            {
                // incase , diff is +- 1

                // means wizard i+1 visibility changes due to cape direction

                capeStartL[i + 1] = capeStartL[i];
                capeStartR[i + 1] = capeStartR[i];
            }
        }

        if (!possible)
        {
            cout << 0 << '\n';
            continue;
        }

        int countValid = 0;

        // check if arrangement starting with left cape works
        if (isValid(capeStartL, a, n))
            countValid++;
        // check if arrangement starting with right cape works
        if (isValid(capeStartR, a, n))
            countValid++;

        cout << countValid << '\n';
    }
    return 0;
}