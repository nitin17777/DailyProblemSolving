#include<bits/stdc++.h>
#define ll long long
using namespace std;
      
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        // Case 1: a > b
        if(a > b)
        {
            /*
                Only possible operation:
                a -> a^1

                Example:
                5 ^ 1 = 4
                4 ^ 1 = 5
            */

            if((a ^ 1) == b)
            {
                cout << y << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }

        // Case 2: a <= b
        else
        {
            // total increments needed
            int totalSteps = b - a;

            /*
                Count odd numbers in [a, b-1]

                Because for odd numbers:
                i ^ 1 = i + 1
            */

            int oddCount =
                ((b + 1) / 2) - ((a + 1) / 2);

            /*
                If direct increment cost is cheaper,
                always use +1 operation
            */

            if(y > x)
            {
                cout << 1LL * totalSteps * x << endl;
            }
            else
            {
                /*
                    Use xor operation on odd numbers
                    because:
                    odd ^ 1 = odd + 1
                */

                int normalMoves = totalSteps - oddCount;

                ll cost =
                    1LL * normalMoves * x +
                    1LL * oddCount * y;

                cout << cost << endl;
            }
        }
    }

    return 0;
}