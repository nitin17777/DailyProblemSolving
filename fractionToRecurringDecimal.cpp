#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
    if (numerator == 0)
        return 0;

    string result;

    if ((numerator < 0) ^ (denominator < 0))
        result += "-";

    long long n = llabs((long long)numerator);
    long long d = llabs((long long)denominator);

    result += to_string(n / d);

    long long remainder = n % d;

    if (remainder == 0)
        return result; // when no fractional part is there

    result += ".";

    unordered_map<long long, int> remainderIndex;

    while (remainder != 0)
    {
        if (remainderIndex.find(remainder) != remainderIndex.end())
        {
            result.insert(remainderIndex[remainder], "(");
            result += ")";

            break;
        }

        remainderIndex[remainder] = result.size();

        remainder *= 10;
        result += to_string(remainder / d);
        remainder %= d;
    }
    return result;
}

// kind of wrong approach

// string fractionToDecimal(int numerator, int denominator)
// {
//     // return fraction in string form
//     double ans = static_cast<double>(numerator) / denominator;
//     ostringstream oss;
//     oss << ans;
//     return oss.str();

//     return to_string(ans);
// }

int main()
{
    cout << fractionToDecimal(1, 2) << endl;

    return 0;
}
