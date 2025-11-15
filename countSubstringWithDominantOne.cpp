#include <iostream>
#include <vector>

using namespace std;

int numberOfSubstrings(string s)
{
    /*Return the number of substrings with dominant ones

    Dominant Ones -> Number of ones >= sqaure of number of zeroes'
    */
    int n = s.size();

    int l = 0, r = n - 1;

    int ans = 0;

    // count the nnumebr of '1' firstly

    int zeroCount = count(s.begin(), s.end(), '0');

    int oneCount = count(s.begin(), s.end(), '1');
    ans += oneCount;

    // we need all substrings : oneCount >= (zeroCount)^2

    // now we are done with single '1' , and time to move towards bigger substrings

    while (l <= r)
    {

        // extend the window size till( number of ones) >= sqr(number of zeroes)

        if (s[l])
    }
}

int main()
{

    cout << numberOfSubstrings("00011") << endl;
    return 0;
}
