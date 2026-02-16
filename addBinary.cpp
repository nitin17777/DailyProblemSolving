#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
        {
            sum += a[i] - '0'; // convertig from string to binary
            i--;
        }

        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        result += (sum % 2) + '0'; // converting integer back to string

        carry = sum / 2; // this will be carry forward to numbers in left side
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{

    string a = "11";
    string b = "1";

    string ans = addBinary(a, b);

    cout << ans << endl;
}
