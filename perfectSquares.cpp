#include <bits/stdc++.h>
using namespace std;

bool isPerfect(int n)
{
    int r = sqrt(n);
    return r * r == n;
}

int numSquares(int n)
{
    // return the least perfect squares that sum to n

    /*
    dp approach is decent but is slow for large input.



    So we will be using a mathematical approach to solve this problem


    Case 1 - > When n is a perfect square => Return 1

    Case 2 -> Can n be written using 2 perfect squares?? => return 2

    n = a2 + b2 => check if (n - b2 ) is a perfect sqaure

    Case 3 -> IF number has form : n = 4^k * (8m +7),Then it cannot be written using 3 sqaures

    Case 4 -> IF not any of the above, return 3

    */

    // 1-> Perfect Square
    if (isPerfect(n))
        return 1;

    // 2 -> check for sum of 2 squares
    for (int i = 1; i <= n; i++)
    {
        if (isPerfect(n - i * i))
            return 2;
    }

    // 3->Legendres's 3 square condition

    int temp = n;

    while (temp % 4 == 0)
        temp /= 4; // Removed all the factors of 4

    // If temp %8 == 7

    if (temp % 8 == 7)
        return 4;

    return 3;
}

int main()
{
    cout << numSquares(12) << endl;
    return 0;
}
