#include <iostream>
#include <vector>
using namespace std;

int smallestNumber(int n)
{
    // return the number equal to greater than 'n' with binary form consisting of only '1'
    //  2^n -1
    //  2^1 - 1 = 1
    //  2^2 - 1 = 3
    //  2^3 - 1  = 7
    //  2^4 - 1 = 15

    int bits = 1;

    while ((1 << bits) - 1 < n)
        bits++;

    return (1 << bits) - 1;
}

int main()
{
    cout << smallestNumber(10) << endl;
    return 0;
}
